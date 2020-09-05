#pragma once
#include <cstdint>
#include <stdexcept>

namespace CycleContainer {
  using usInt = std::int64_t;
  using byte = char;

  template <class T> class Container {
  public:
    Container();
    Container(std::uint64_t const capacity);
    Container(T const & value, std::uint64_t const size);
    Container(Container const & other);
    ~Container();
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
  }
}
