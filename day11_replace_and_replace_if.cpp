//
// Created by LongXiaJun on 2018/12/17 0017.
//

#include "day11_replace_and_replace_if.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <functional>


namespace demo_replace_and_replace_if {
    namespace definition {
        //Possible definition
        template<typename ForwardIt, typename T>
        void replace(ForwardIt first, ForwardIt last,
                     const T &old_value, const T &new_value) {
            for (; first != last; ++first) {
                if (*first == old_value) {
                    *first = new_value;
                }
            }
        }

        template<typename ForwardIt, typename UnaryPredicate, typename T>
        void replace_if(ForwardIt first, ForwardIt last,
                        UnaryPredicate p, const T &new_value) {
            for (; first != last; ++first) {
                if (p(*first)) {
                    *first = new_value;
                }
            }
        }
    }


    void stl_replace_and_replace_if() {
        std::cout << "STL replace and replace_if usage demo: \nThe source array is: ";
        std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        std::for_each(s.begin(), s.end(), [](auto const &a) { std::cout << a << " "; });
        std::replace(s.begin(), s.end(), 8, 88);
        std::cout << "\nAfter replace 8 with 88, the array is: ";
        for (int a : s) {
            std::cout << a << " ";
        }
        std::cout << '\n';


        std::replace_if(s.begin(), s.end(),
                        std::bind1st(std::less<int>(), 5), 60);
        std::cout << "After replace the value > 5 with 60, the array is: ";
        for (int a : s) {
            std::cout << a << " ";
        }
        std::cout << '\n';
    }
}