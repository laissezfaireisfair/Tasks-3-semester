#pragma once

#include <cstdint>
#include <stdexcept>

namespace CycleContainer {
  using usInt = std::uint64_t;
  using byte = char;

  template <class T> class Container {
  public:
    Container() noexcept {
      alloc_body(0);
      m_begin = 0;
      m_size  = 0;
    }

    explicit Container(std::uint64_t const capacity) {
      alloc_body(capacity);
      m_begin = 0;
      m_size  = 0;
    }

    Container(std::uint64_t const size, T const & value) {
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

    std::uint64_t get_size() const noexcept {
      return m_size;
    }

    std::uint64_t get_capacity() const noexcept {
      return m_capacity;
    }

    bool is_empty() const noexcept {
      return m_size == 0;
    }

    T& at(std::uint64_t const place) {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return m_body[realPlace(place)];
    }
    T const & at(std::uint64_t const place) const {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return m_body[realPlace(place)];
    }

    T& operator[](std::uint64_t const place) {
      return at(place);
    }
    T const & operator[](std::uint64_t const place) const {
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
      usInt placeNew = (m_capacity + m_begin - 1) % m_capacity;
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

    void rotate_forward(std::uint64_t const distance) {
      if (m_size < m_capacity)
        throw std::logic_error("Try to rotate not fulled buffer");
      usInt positiver;
      for (positiver = 0; positiver + m_begin < distance; positiver += m_capacity) {}
      m_begin = positiver + m_begin - distance;
    }

    void rotate_back(std::uint64_t const distance) {
      if (m_size < m_capacity)
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

  private:
    usInt m_capacity; // Potential size of container
    usInt m_size;     // Number of elements
    usInt m_begin;
    byte *m_memPool;
    T    *m_body;

    usInt realPlace(usInt const place) const noexcept {
      return (m_begin + place) % m_capacity;
    }

    void alloc_body(usInt const capacity) {
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
      for (m_size = 0; m_size < m_size; ++m_size)
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
