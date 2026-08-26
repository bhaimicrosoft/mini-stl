#include <cassert>
#include <iostream>
#include "ministl/memory/raw_buffer.hpp"
using namespace miniSTL;

int main() {
    RawBuffer<int> a(10);
    RawBuffer<int> b(20);

    b = std::move(a);

    assert(a.data() == nullptr);
    assert(a.capacity() == 0);

    assert(b.data() != nullptr);
    assert(b.capacity() == 10);

    RawBuffer<int> buffer;

    assert(buffer.capacity() == 0);
    assert(buffer.data() == nullptr);

    std::cout << "All tests passed successfully!!!!" << std::endl;

    return 0;
}
