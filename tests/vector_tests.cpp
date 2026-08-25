#include <cassert>

#include "ministl/containers/vector.hpp"

using namespace ministl;

void TestEmptyVector()
{
    Vector<int> v;

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.begin() == v.end());
}

void TestReserve()
{
    Vector<int> v;

    v.reserve(16);

    assert(v.size() == 0);
    assert(v.capacity() == 16);
}

void TestMultipleReserve()
{
    Vector<int> v;

    v.reserve(8);

    const auto firstCapacity = v.capacity();

    v.reserve(4);

    assert(v.capacity() == firstCapacity);
}

void TestDataPointer()
{
    Vector<int> v;

    v.reserve(10);

    assert(v.data() != nullptr);
}

int main()
{
    TestEmptyVector();
    TestReserve();
    TestMultipleReserve();
    TestDataPointer();

    return 0;
}