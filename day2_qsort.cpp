//
// Created by LongXiaJun on 2018/12/8 0008.
//

#include "day2_qsort.h"
#include <iostream>
#include <algorithm>

namespace demo_qsort {

    void stl_qsort() {
        std::cout << "STL qsort usage demo: " << std::endl;

        int a[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
        constexpr std::size_t size = sizeof a / sizeof(a[0]);
        std::cout << "Before: ";
        std::for_each(std::begin(a), std::end(a), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;

        std::qsort(a, size, sizeof *a, [](const void *lhs, const void *rhs) {
            int arg1 = *static_cast<const int *>(lhs);
            int arg2 = *static_cast<const int *>(rhs);
            if (arg1 < arg2) return -1;
            if (arg1 > arg2) return 1;
            return 0;
        });

        std::cout << "After qsort is: ";
        std::for_each(std::begin(a), std::end(a), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
    }


}