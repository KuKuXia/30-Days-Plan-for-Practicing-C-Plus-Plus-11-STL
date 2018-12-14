//
// Created by LongXiaJun on 2018/12/14 0014.
//

#include "day8_fill_and_fill_n.h"
#include <iostream>
#include <vector>
#include <algorithm>


namespace demo_fill_and_fill_n {
    namespace definition {
        // Possible definition
        template<typename ForwardIt, typename T>
        void fill(ForwardIt first, ForwardIt last, const T &value) {
            for (; first != last; first++) {
                *first++ = value;
            }
        }

        template<typename OutputIt, typename Size, typename T>
        OutputIt fill_n(OutputIt first, Size count, const T &value) {
            for (Size i = 0; i < count; ++i) {
                *first++ = value;
            }
            return first;
        }
    }

    void stl_fill_and_fill_n() {
        std::cout << "STL fill and fill_n usage demo: \n";
        std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "Before fill the value of 5, the source is: ";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << std::endl;

        std::fill(v.begin(), v.end(), 5);
        std::cout << "After fill, the source is: ";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << std::endl;

        std::fill_n(v.begin(), 6, 10);
        std::cout << "After fill_n, n = 6, value = 10, the source is: ";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << std::endl;

    }


}