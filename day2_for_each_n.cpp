//
// Created by LongXiaJun on 2018/12/8 0008.
//

#include "day2_for_each_n.h"
#include <vector>
#include <algorithm>
#include <iostream>


namespace demo_for_each_n {
    // Possible definition
    namespace definition_for_each_n {
        template<typename InputIt, typename Size, typename UnarFunction>
        InputIt for_each_n(InputIt first, Size n, UnarFunction f) {
            for (Size i = 0; i < n; ++first, (void) ++i) {
                f(*first);
            }
            return first;
        }
    }

    void stl_for_each_n() {
        std::cout << "STL for_each_n usage demo: " << std::endl;
        std::vector<int> nums{1, 2, 3, 4, 5};
        std::cout << "Before: ";
        std::for_each(nums.begin(), nums.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
        definition_for_each_n::for_each_n(nums.begin(), 4, [](auto &a) { a *= 2; });

        std::cout << "After for_each_n is: ";
        std::for_each(nums.begin(), nums.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
    }



}

