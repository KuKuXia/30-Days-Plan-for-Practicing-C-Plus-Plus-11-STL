//
// Created by LongXiaJun on 2018/12/8 0008.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "day2_for_each.h"



namespace demo_for_each {
    namespace definition_for_each {
        // Possible Definition
        template<typename InputIt, typename UnaryFunction>
        UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f) {
            for (; first != last; ++first) {
                f(*first);
            }
            return f;
        }
    }

    struct Sum {
        Sum() : sum{0} {}

        void operator()(int n) { sum += n; }

        int sum;
    };

    std::vector<int> nums{3, 4, 4, 5, 5, 6, 6, 7, 2};
    auto print = [](const int &n) { std::cout << " " << n; };


    void stl_for_each() {
        std::cout << "STL for_each usage demo: " << std::endl;
        std::cout << "Before: ";
        std::for_each(nums.begin(), nums.end(), print);
        std::cout << "\n";

        std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

        Sum s = std::for_each(nums.begin(), nums.end(), Sum());

        std::cout << "After add one to each object: ";
        definition_for_each::for_each(nums.begin(), nums.end(), print);
        std::cout << "\n";
        std::cout << "Total Sum: " << s.sum << std::endl;
    }


}