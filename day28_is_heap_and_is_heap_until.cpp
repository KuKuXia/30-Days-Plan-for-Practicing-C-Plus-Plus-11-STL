//
// Created by LongXiaJun on 2019/1/3 0003.
//

#include "day28_is_heap_and_is_heap_until.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace demo_is_heap_and_is_heap_until {
    namespace definition {
        // Possible definition


    }

    void stl_is_heap_and_is_heap_until() {
        std::cout << "STL is_heap usage demo:\n";
        std::vector<int> v{3, 1, 4, 1, 5, 9};

        std::cout << "initially, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        if (!std::is_heap(v.begin(), v.end())) {
            std::cout << "making heap...\n";
            std::make_heap(v.begin(), v.end());
        }

        std::cout << "after make_heap, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::cout << "STL is_heap_until usage demo:\n";

        // 很可能扰乱堆
        v.push_back(2);
        v.push_back(6);

        auto heap_end = std::is_heap_until(v.begin(), v.end());

        std::cout << "all of v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::cout << "only heap: ";
        for (auto i = v.begin(); i != heap_end; ++i) std::cout << *i << ' ';
        std::cout << '\n';
    }
}
