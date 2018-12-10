//
// Created by LongXiaJun on 2018/12/8 0008.
//

#include "day2_bsearch.h"
#include <iostream>
#include <algorithm>

namespace demo_bsearch {
    void stl_bsearch() {
        const int ARR_SIZE = 8;
        int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

        std::cout << "STL bsearch usage demo:" << std::endl << "Nums: ";
        std::for_each(std::begin(arr), std::end(arr), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        auto compare = [](const void *ap, const void *bp) {
            auto a = static_cast<const int *>(ap);
            auto b = static_cast<const int *>(bp);
            if (*a < *b)
                return -1;
            else if (*a > *b)
                return 1;
            else
                return 0;
        };

        int key1 = 4;
        int *p1 = (int *) std::bsearch(&key1, arr, ARR_SIZE, sizeof(arr[0]), compare);
        if (p1)
            std::cout << "value " << key1 << " found at position " << std::distance(std::begin(arr), p1) << '\n';
        else
            std::cout << "value " << key1 << " not found\n";

        int key2 = 9;
        int *p2 = (int *) std::bsearch(&key2, arr, ARR_SIZE, sizeof(arr[0]), compare);
        if (p2)
            std::cout << "value " << key2 << " found at position " << std::distance(std::begin(arr), p2) << '\n';
        else
            std::cout << "value " << key2 << " not found\n";
    }
}

