#pragma once

#include <cstdint>
#include <stdexcept>

namespace CycleContainer {
  using size_t = std::size_t;
  using byte = char;

  template <class T> class Container {
  public:
    Container() noexcept {
      alloc_body(0);
      m_begin = 0;
      m_size  = 0;
    }

    explicit Container(size_t const capacity) {
      alloc_body(capacity);
      m_begin = 0;
      m_size  = 0;
    }

    Container(size_t const size, T const & value) {
      alloc_body(size);
      m_begin = 0;
      for (m_size = 0; m_size < size; ++m_size)
        m_body[m_size] = value;
    }

    Container(Container<T> const & other) {
      alloc_body(other.m_capacity);
      copy_body(other);
    }

    ~Container() {
      deinitialise();
    }

    size_t get_size() const noexcept {
      return m_size;
    }

    size_t get_capacity() const noexcept {
      return m_capacity;
    }

    bool is_empty() const noexcept {
      return m_size == 0;
    }

    T& at(size_t const place) {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return m_body[realPlace(place)];
    }
    T const & at(size_t const place) const {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return m_body[realPlace(place)];
    }

    T& operator[](size_t const place) {
      return at(place);
    }
    T const & operator[](size_t const place) const {
      return at(place);
    }

    T& get_front() {
      return at(0);
    }
    T const & get_front() const {
      return at(0);
    }

    T& get_back() {
      return at(m_size - 1);
    }
    T const & get_back() const {
      return at(m_size - 1);
    }

    void push_back(T const & elem) {
      if (m_size == m_capacity)
        throw std::overflow_error("Pushing to full container");
      m_body[realPlace(m_size)] = elem;
      ++m_size;
    }

    void push_front(T const & elem) {
      if (m_size == m_capacity)
        throw std::overflow_error("Pushing to full container");
      size_t placeNew = (m_capacity + m_begin - 1) % m_capacity;
      m_body[placeNew] = elem;
      m_begin = placeNew;
      ++m_size;
    }

    void pop_front() {
      if (is_empty())
        throw std::underflow_error("Try to pop empty container");
      m_body[m_begin].~T();
      --m_size;
      if (m_size == 0)
        m_begin = 0;
      else
        m_begin = realPlace(++m_begin);
    }

    void pop_back() {
      if (is_empty())
        throw std::underflow_error("Try to pop empty container");
      m_body[realPlace(m_begin + m_size)].~T();
      --m_size;
      if (m_size == 0)
        m_begin = 0;
    }

    void clean() {
      for (; m_size > 0; --m_size)
        m_body[realPlace(m_size - 1)].~T();
      m_begin = 0;
    }

    void rotate_forward(size_t const distance) {
      if (!full())
        throw std::logic_error("Try to rotate not fulled buffer");
      size_t positiver;
      for (positiver = 0; positiver + m_begin < distance; positiver += m_capacity) {}
      m_begin = positiver + m_begin - distance;
    }

    void rotate_back(size_t const distance) {
      if (!full())
        throw std::logic_error("Try to rotate not fulled buffer");
      m_begin = (m_begin + distance) % m_capacity;
    }

    Container<T>& operator=(Container<T> const & other)  {
      if (m_capacity == other.m_capacity) {
        clean();
        copy_body(other);
        return *this;
      }
      deinitialise();
      alloc_body(other.m_capacity);
      copy_body(other);
      return *this;
    }

    int reserve() const noexcept {
      return m_capacity - m_size;
    }

    bool full() const noexcept {
      return m_capacity == m_size;
    }

    bool is_linear() const noexcept {
      return m_begin == 0;
    }

    // Also linearize in realloc case (in does not really affect efficiency)
    void set_capacity(size_t const newCapacity) {
      if (newCapacity == m_capacity)
        return;
      if (newCapacity < m_size)
        throw std::length_error("Try to non-explicit cut existing elements");
      byte *oldMemPool = m_memPool;
      T *oldBody = m_body;
      alloc_body(newCapacity);
      for (size_t i = 0; i < m_size; ++i)
        m_body[i] = oldBody[realPlace(i)];
      m_begin = 0;
      delete[] oldMemPool;
    }

  void cut(size_t const newSize) {
    if (newSize > m_size)
      throw std::invalid_argument("Wrong size to cut");
    for (;m_size > newSize; --m_size)
      m_body[m_size - 1].~T();
  }

  void expand(size_t const newSize, T const & elem) {
    if (newSize <= m_size)
      throw std::logic_error("Wrong size to expand");
    if (newSize > m_capacity)
      set_capacity(newSize);
    while(m_size < newSize)
      push_back(elem);
  }

  // If can, replace with cut/expand. It may call extra constructor
  void resize(size_t const newSize, T const & elem = T()) {
    if (m_size < newSize)
      expand(newSize, elem);
    if (m_size > newSize)
      cut(newSize);
  }

  T* linearize() {
    if (is_linear())
      return m_body;
    byte *oldMemPool = m_memPool;
    T *oldBody = m_body;
    alloc_body(m_capacity);
    for (size_t i = 0; i < m_size; ++i)
      m_body[i] = oldBody[realPlace(i)];
    m_begin = 0;
    delete[] oldMemPool;
    return m_body;
  }

  void insert(size_t const place, T const & elem) {
    if (m_size == m_capacity)
      throw std::overflow_error("Try to insert to full buffer");
    if (place > m_size)
      throw std::invalid_argument("Wrong insert position");
    if (place != m_size) { // Need to move tail forward
      for (size_t i = 0; i < m_size - place; ++i) {
        size_t const elemPos = realPlace(m_size - i - 1);
        m_body[(elemPos + 1) % m_capacity] = m_body[elemPos];
      }
    }
    m_body[realPlace(place)] = elem;
    ++m_size;
  }

  /// [first, last), dont do anyting in case first == last
  void erase(size_t const first, size_t const last) {
    if (first >= m_size || last > m_size)
      throw std::length_error("Try to erase after end");
    if (first > last)
      throw std::invalid_argument("Erasing [first, last), first > last");
    for (size_t i = first; i < last; ++i)
      m_body[i].~T();
    if (last < m_size) // Need to move tail back
      for (size_t i = 0; i < m_size - last; ++i)
        m_body[realPlace(first + i)] = m_body[realPlace(first + i + 1)];
    m_size -= last - first;
  }

  bool operator==(Container<T> const & other) const {
    if (m_size != other.size)
      return false;
    for (size_t i = 0; i < m_size; ++i)
      if (at(i) != other.at(i))
        return false;
    return true;
  }

  bool operator!=(Container<T> const & other) const {
    return !(*this == other);
  }

  private:
    size_t m_capacity; // Potential size of container
    size_t m_size;     // Number of elements
    size_t m_begin;
    byte *m_memPool;
    T    *m_body;

    size_t realPlace(size_t const place) const noexcept {
      return (m_begin + place) % m_capacity;
    }

    void alloc_body(size_t const capacity) {
      m_capacity = capacity;
      if (capacity == 0) {
        m_memPool = nullptr;
        m_body = nullptr;
      } else {
        m_memPool = new byte[sizeof(T) * capacity];
        m_body = reinterpret_cast<T*>(m_memPool);
      }
    }

    /// Needs allocated and clean this->body to work properly
    void copy_body(Container<T> const & other) {
      m_begin = other.m_begin;
      for (m_size = 0; m_size < other.m_size; ++m_size)
        m_body[m_size] = other.m_body[m_size];
    }

    void deinitialise() {
      clean();
      delete[] m_memPool;
      m_memPool = nullptr;
      m_body = nullptr;
      m_capacity = 0;
    }
  };
}
