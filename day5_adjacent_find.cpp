//
// Created by LongXiaJun on 2018/12/11 0011.
//

#include "day5_adjacent_find.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace demo_adjacent_find {
    namespace definition {
        // Possible definition
        template<class ForwardIt>
        ForwardIt adjacent_find(ForwardIt first, ForwardIt last) {
            if (first == last) {
                return last;
            }
            ForwardIt next = first;
            ++next;
            for (; next != last; ++first, ++next) {
                if (*first == *next) {
                    return first;
                }
            }
            return last;
        }

        template<class ForwardIt, class BinaryPredicate>
        ForwardIt adjacent_find(ForwardIt first, ForwardIt last,
                                BinaryPredicate p) {
            if (first == last) {
                return last;
            }
            ForwardIt next = first;
            ++next;
            for (; next != last; ++next, ++first) {
                if (p(*first, *next)) {
                    return first;
                }
            }
            return last;
        }
    }

    void std_adjacent_find() {
        std::cout << "STL adjacent_find usage demo: " << std::endl;
        std::vector<int> Source{0, 1, 2, 3, 4, 5, 6, 6, 7, 8};
        auto il = std::adjacent_find(Source.begin(), Source.end());
        std::for_each(Source.begin(), Source.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
        if (il == Source.end()) {
            std::cout << "No matching adjacent elements\n";
        } else {
            std::cout << "The first adjacent pair of equal elements: " << *il << " at: "
                      << std::distance(Source.begin(), il) << std::endl;
        }

        auto i2 = std::adjacent_find(Source.begin(), Source.end(), std::greater<int>());
        if (i2 == Source.end()) {
            std::cout << "The entire vector is sorted in ascending order\n";
        } else {
            std::cout << "The last element in the non-decreasing subsequence is at: "
                      << std::distance(Source.begin(), i2) << '\n';
        }
    }
}

