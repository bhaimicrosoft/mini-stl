#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <utility>

namespace miniSTL
{
  template <typename T>
  class RawBuffer
  {
  public:
    RawBuffer() = default;

    explicit RawBuffer(const std::size_t capacity) : m_capacity(capacity)
    {
      if (capacity > 0)
      {
        m_data = static_cast<T *>(::operator new(sizeof(T) * capacity));
      }
    }

    ~RawBuffer()
    {
      ::operator delete(m_data);
    }

    // Delete copy constructor and assignment operator
    RawBuffer(const RawBuffer &) = delete;

    RawBuffer &operator=(const RawBuffer &) = delete;

    // Enable move semantics
    RawBuffer(RawBuffer &&other) noexcept : m_data(std::exchange(other.m_data, nullptr)),
                                            m_capacity(std::exchange(other.m_capacity, 0))
    {
    }

    RawBuffer &operator=(RawBuffer &&other) noexcept
    {
      if (this == &other)
      {
        return *this;
      }
      delete m_data;

      m_data = std::exchange(other.m_data, nullptr);
      m_capacity = std::exchange(other.m_capacity, 0);
      return *this;
    }

    void swap(RawBuffer &other) noexcept
    {
      using std::swap;

      swap(m_data, other.m_data);
      swap(m_capacity, other.m_capacity);
    }

    friend void swap(RawBuffer& left, RawBuffer& right) noexcept
    {
       left.swap(right);
    }

    T *data() noexcept
    {
      return m_data;
    }

    const T *data() const noexcept
    {
      return m_data;
    }

    [[nodiscard]] std::size_t capacity() const noexcept
    {
      return m_capacity;
    }

  private:
    T *m_data{nullptr};
    std::size_t m_capacity{0};
  };
}
