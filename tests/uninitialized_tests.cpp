#include <cassert>
#include "test_types.hpp"
#include <iostream>
#include "ministl/memory/raw_buffer.hpp"
#include "ministl/memory/lifetime.hpp"
#include "ministl/memory/uninitialized.hpp"

void TestUninitializedCopy()
{
    Tracker::Reset();
    {
        ministl::RawBuffer<Tracker> source(3);

        for (size_t i = 0; i < 3; ++i)
        {
            ministl::construct_at(source.data() + i);
        }

        ministl::RawBuffer<Tracker> destination(3);

        ministl::uninitialized_copy(source.data(), source.data() + 3, destination.data());

        assert(Tracker::copies == 3);
        assert(Tracker::moves == 0);

        ministl::destroy_range(source.data(), source.data() + 3);
        ministl::destroy_range(destination.data(), destination.data() + 3);
    }

    assert(Tracker::constructions == Tracker::destructions);
}

void TestUninitializedMove()
{
    Tracker::Reset();
    {
        ministl::RawBuffer<Tracker> source(3);
        for (size_t i = 0; i < 3; ++i)
        {
            ministl::construct_at(source.data() + i);
        }

        ministl::RawBuffer<Tracker> destination(3);

        ministl::uninitialized_move(source.data(), source.data() + 3, destination.data());

        assert(Tracker::copies == 0);
        assert(Tracker::moves == 3);

        ministl::destroy_range(source.data(), source.data() + 3);
        ministl::destroy_range(destination.data(), destination.data() + 3);
    }

    assert(Tracker::constructions == Tracker::destructions);
}

int main()
{
    TestUninitializedCopy();
    TestUninitializedMove();
    std::cout<<"\n\nAll tests passed!!\n\n";

    return 0;
}
