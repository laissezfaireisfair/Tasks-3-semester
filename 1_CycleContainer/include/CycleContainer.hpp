#pragma once

#include <cstdint>
#include <stdexcept>

namespace CycleContainer {
  using usInt = std::int64_t;
  using byte = char;

  template <class T> class Container {
  public:
    Container() {
      alloc_body(0);
      m_begin = 0;
      m_size  = 0;
    }

    Container(std::uint64_t const capacity) {
      alloc_body(capacity);
      m_begin = 0;
      m_size  = 0;
    }

    Container(T const & value, std::uint64_t const size) {
      alloc_body(size);
      m_begin = 0;
      for (m_size = 0; m_size < size; ++m_size)
        m_body[m_size] = value;
    }

    Container(Container<T> const & other) {
      alloc_body(other.capacity);
      m_begin = other.begin;
      for (m_size = 0; m_size < size; ++m_size)
        m_body[m_size] = other.body[m_size];
    }

    ~Container() {
      deinitialise();
    }

    std::uint64_t get_size() const {
      return m_size;
    }

    std::uint64_t get_capacity() const {
      return m_capacity;
    }

    bool is_empty() const {
      return m_size == 0;
    }

    T& at(std::uint64_t const place) const {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return m_body[realPlace(place)];
    }

    T& operator[](std::uint64_t const place) const {
      if (place > m_size)
        throw std::out_of_range("Try to reach non-initialised elem of buffer");
      return at(place);
    }

    T& get_front() const {
      if (size == 0)
        throw std::out_of_range("Try to reach elem of empty buffer");
      return at(realPlace(0));
    }

    T& get_back() const {
      if (size == 0)
        throw std::out_of_range("Try to reach elem of empty buffer");
      return at(realPlace(m_size - 1));
    }

    void push_back(T const & elem);

    void push_front(T const & elem);

    void pop_front();

    void pop_back();

    void clean() {
      for (; m_size > 0; --m_size)
        m_body[realPlace(m_size)].~T();
      m_begin = 0;
    }

    void rotate_forward(std::uint64_t const distance);

    void rotate_back(std::uint64_t const distance);

    Container<T>& operator=(Container<T> const & other);

  private:
    usInt m_capacity;
    usInt m_size;
    usInt m_begin;
    byte *m_memPool;
    T    *body;

    usInt realPlace(usInt const place) const {
      return (m_begin + place) % m_capaticy;
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

    void deinitialise() {
      clean();
      delete[] m_memPool;
      m_memPool = nullptr;
      m_body = nullptr;
      m_capacity = 0;
    }
  }
}
