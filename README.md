# Mini STL

A modern C++20 implementation of STL-inspired containers, smart pointers,
iterators, and allocator-aware data structures.

This project is designed to explore:

- manual memory management
- RAII and ownership semantics
- copy and move semantics
- allocator-aware containers
- iterator design
- exception safety
- generic programming
- concurrency fundamentals
- testing and performance analysis

> This is an educational implementation and is not intended to replace the
> C++ Standard Library.

## Planned Components

### Memory

- `UniquePtr`
- `SharedPtr`
- `WeakPtr`
- custom deleters
- reference-control blocks

### Allocators

- `MallocAllocator`
- `PoolAllocator`
- `ArenaAllocator`

### Containers

- `Vector`
- `String`
- `SmallVector`
- `List`
- `HashMap`

## Implemented

### Memory

- RawBuffer<T>
    - raw memory allocation
    - move-only semantics
    - ownership transfer
    - capacity management



## Build

```bash
cmake -S . -B build
cmake --build build