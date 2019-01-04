//
// Created by LongXiaJun on 2019/1/4 0004.
//

#include "day29_make_heap_and_sort_heap.h"
#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_make_heap_and_sort_heap {


    void stl_make_heap_and_sort_heap() {
        std::cout << "STL make_heap_and_sort_heap usage demo:\n";
        std::vector<int> v{3, 1, 4, 1, 5, 9};

        std::cout << "initially, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::make_heap(v.begin(), v.end());

        std::cout << "after make_heap, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::pop_heap(v.begin(), v.end());
        auto largest = v.back();
        v.pop_back();
        std::cout << "largest element: " << largest << '\n';

        std::cout << "after removing the largest element, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::sort_heap(v.begin(), v.end());

        std::cout << "After sorted:\t";
        for (const auto &i : v) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}