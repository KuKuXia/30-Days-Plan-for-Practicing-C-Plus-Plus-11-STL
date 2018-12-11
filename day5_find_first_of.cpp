//
// Created by LongXiaJun on 2018/12/11 0011.
//

#include "day5_find_first_of.h"
#include <iostream>
#include <vector>
#include <algorithm>


namespace demo_find_first_of {
    namespace definition {
        // Possible definition
        template<typename InputIt, typename ForwardIt>
        InputIt find_first_of(InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last) {
            for (; first != last; ++first) {
                for (ForwardIt it = s_first; it != s_last; ++it) {
                    if (*first == *it) {
                        return first;
                    }
                }
            }
            return last;
        }

        template<typename InputIt, typename ForwardIt, typename BinaryPredicate>
        InputIt find_first_of(InputIt first, InputIt last,
                              ForwardIt s_first, ForwardIt s_last,
                              BinaryPredicate p) {
            for (; first != last; ++first) {
                for (ForwardIt it = s_first; it != s_last; ++it) {
                    if (p(*first, *it)) {
                        return first;
                    }
                }
            }
            return last;

        }
    }

    void stl_find_first_of() {

        std::cout << "STL find_first_of usage demo: " << std::endl;

        std::vector<int> source{0, 2, 3, 26, 6, 4, 5, 4, 32, 2, 3, 9};
        std::vector<int> target{9, 8, 12, 11, 23, 4, 5,};
        std::cout << "Source is: ";
        std::for_each(source.begin(), source.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
        std::cout << "Target is: ";
        std::for_each(target.begin(), target.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;


        auto result = std::find_first_of(source.begin(), source.end(), target.begin(), target.end());
        if (result != source.end()) {
            std::cout << "Find the " << *result << " in source" << std::endl;
        } else {
            std::cout << "No elements of source were equal to target: " << std::endl;
        }
    }

}
