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
      m_size = 0;
    }
    Container(std::uint64_t const capacity) {
      alloc_body(capacity);
      m_size = 0;
    }
    Container(T const & value, std::uint64_t const size) {
      alloc_body(size);
      for (m_size = 0; m_size < size; ++m_size)
        m_begin[m_size] = value;
    }
    Container(Container const & other) {
      alloc_body(other.capacity);
      for (m_size = 0; m_size < size; ++m_size)
        m_begin[m_size] = other.begin[m_size];
    }
    ~Container() {
      deinitialise();
    }
    std::uint64_t get_size() const;
    std::uint64_t get_capacity() const;
    bool is_empty() const;
    T& at(std::uint64_t const place) const;
    T& operator[](std::uint64_t const place) const;
    T& front() const;
    T& back() const;
    void push_back(T const & elem);
    void pop_front();
    void clean();
    void rotate_forward(std::uint64_t const distance);
    void rotate_back(std::uint64_t const distance);
    T& operator=(T const & other);
  private:
    usInt m_capacity;
    usInt m_size;
    byte *m_memPool;
    T    *m_begin;
    void alloc_body(usInt const capacity) {
      m_capacity = capacity;
      if (capacity == 0) {
        m_memPool = nullptr;
        m_begin = nullptr;
      } else {
        m_memPool = new byte[sizeof(T) * capacity];
        m_begin = reinterpret_cast<T*>(m_memPool);
      }
    }
    void deinitialise() {
      clean();
      delete[] m_memPool;
      m_memPool = nullptr;
      m_begin = nullptr;
      capacity = 0;
    }
  }
}
