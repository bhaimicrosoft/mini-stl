#pragma once
#include <cstddef>
#include <utility>

#include "ministl/memory/lifetime.hpp"
#include "ministl/memory/raw_buffer.hpp"
#include "ministl/memory/uninitialized.hpp"

namespace miniSTL
{
  template <typename T>
  class Vector
  {
  public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;

    Vector() = default;

    Vector(const Vector &other)
        : m_storage(other.m_size),
          m_size(0)
    {
      if (other.m_size == 0)
      {
        return;
      }

      uninitialized_copy(
          other.begin(),
          other.end(),
          m_storage.data());

      m_size = other.m_size;
    }

    Vector(Vector &&other) noexcept
        : m_storage(std::move(other.m_storage)),
          m_size(std::exchange(other.m_size, 0))
    {
    }

    ~Vector()
    {
      clear();
    }

    Vector &operator=(Vector &&other) noexcept
    {
      if (this == &other)
      {
        return *this;
      }

      clear();

      m_storage = std::move(other.m_storage);
      m_size = std::exchange(other.m_size, 0);

      return *this;
    }

    void swap(Vector &other) noexcept
    {
      using std::swap;

      swap(m_storage, other.m_storage);
      swap(m_size, other.m_size);
    }

    void clear() noexcept
    {
      if (m_size == 0)
      {
        return;
      }

      destroy_range(data(), data() + m_size);
      m_size = 0;
    }

    [[nodiscard]] size_type size() const noexcept
    {
      return m_size;
    }

    [[nodiscard]] size_type capacity() const noexcept
    {
      return m_storage.capacity();
    }

    [[nodiscard]] bool empty() const noexcept
    {
      return m_size == 0;
    }

    pointer data() noexcept
    {
      return m_storage.data();
    }

    const_pointer data() const noexcept
    {
      return m_storage.data();
    }

    pointer begin() noexcept
    {
      return data();
    }

    const_pointer begin() const noexcept
    {
      return data();
    }

    pointer end() noexcept
    {
      return m_size == 0 ? data() : data() + m_size;
    }

    const_pointer end() const noexcept
    {
      return m_size == 0 ? data() : data() + m_size;
    }

    reference operatorsize_type index noexcept
    {
      return data()[index];
    }

    const_reference operatorsize_type index const noexcept
    {
      return data()[index];
    }

    void reserve(size_type new_capacity)
    {
      if (new_capacity <= capacity())
      {
        return;
      }

      RawBuffer<T> new_storage(new_capacity);

      uninitialized_move(
          begin(),
          end(),
          new_storage.data());

      destroy_range(begin(), end());

      m_storage = std::move(new_storage);
    }

    template <typename... Args>
    reference emplace_back(Args &&...args)
    {
      if (m_size == capacity())
      {
        grow();
      }

      pointer location = data() + m_size;

      construct_at(
          location,
          std::forward<Args>(args)...);

      ++m_size;

      return *location;
    }

    void push_back(const T &value)
    {
      emplace_back(value);
    }

    void push_back(T &&value)
    {
      emplace_back(std::move(value));
    }

  private:
    void grow()
    {
      const size_type new_capacity =
          capacity() == 0 ? 1 : capacity() * 2;

      reserve(new_capacity);
    }

    RawBuffer<T> m_storage;
    size_type m_size{0};
  };

  template <typename T>
  void swap(Vector<T> &left, Vector<T> &right) noexcept
  {
    left.swap(right);
  }
}