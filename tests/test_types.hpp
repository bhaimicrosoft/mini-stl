#pragma once

struct Tracker {
    static inline int constructions = 0;
    static inline int destructions = 0;
    static inline int copies = 0;
    static inline int moves = 0;

    Tracker() {
        ++constructions;
    }

    Tracker(const Tracker &) {
        ++constructions;
        ++copies;
    }

    Tracker(Tracker &&) noexcept {
        ++constructions;
        ++moves;
    }

    ~Tracker() {
        ++destructions;
    }

    static void Reset() {
        constructions = 0;
        destructions = 0;
        copies = 0;
        moves = 0;
    }
};
