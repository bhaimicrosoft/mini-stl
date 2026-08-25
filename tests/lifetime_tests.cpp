#include <cassert>

#include "ministl/memory/raw_buffer.hpp"
#include "ministl/memory/lifetime.hpp"

struct Tracker
{
    static inline int constructions = 0;
    static inline int destructions = 0;

    Tracker()
    {
        ++constructions;
    }

    ~Tracker()
    {
        ++destructions;
    }
};

int main()
{
    {
        ministl::RawBuffer<Tracker> buffer(1);

        auto* obj =
            ministl::construct_at(buffer.data());

        ministl::destroy_at(obj);
    }

    assert(
        Tracker::constructions == 1);

    assert(
        Tracker::destructions == 1);
}