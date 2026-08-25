#pragma once
#include "../memory/raw_buffer.hpp"
#include "ministl/memory/lifetime.hpp"
#include "ministl/memory/uninitialized.hpp"


template<typename T>
class Vector
{
public:
    Vector() = default;

    ~Vector()
    {
        ministl::destroy_range(m_storage.data(), m_storage.data() + m_size);
    }

    void reserve(std::size_t newCapacity)
    {
        if (newCapacity <= capacity())
        {
            return;
        }

        ministl::RawBuffer<T> newStorage(newCapacity);

        ministl::uninitialized_move(m_storage.data(), m_storage.data() + m_size, newStorage.data());

        ministl::destroy_range(m_storage.data(), m_storage.data() + m_size);

        m_storage = std::move(newStorage);
        m_capacity = newCapacity;
    }

    [[nodiscard]] size_t size() const noexcept
    {
        return m_size;
    }

    [[nodiscard]] size_t capacity() const noexcept
    {
        return m_capacity;
    }

    T *data() noexcept
    {
        return m_storage.data();
    }

    const T *data() const noexcept
    {
        return m_storage.data();
    }

    T *begin() noexcept
    {
        return data();
    }

    T *end() noexcept
    {
        return data() + m_size;
    }

    T& operator[](std::size_t index)
    {
        return data()[index];
    }

    const T& operator[](std::size_t index) const
    {
        return data()[index];
    }

private:
    ministl::RawBuffer<T> m_storage;
    std::size_t m_size{0};
    std::size_t m_capacity{0};
};
