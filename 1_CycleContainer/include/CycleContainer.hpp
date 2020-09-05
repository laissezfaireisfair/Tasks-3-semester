#pragma once
#include <cstdint>
#include <stdexcept>

namespace CycleContainer {
  using usInt = std::int64_t;

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
  }
}
