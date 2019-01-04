//
// Created by LongXiaJun on 2019/1/4 0004.
//

#include "day29_pop_heap_and_push_heap.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace demo_pop_heap_and_push_heap {

    void stl_pop_heap_and_push_heap() {
        std::cout << "STL pop_heap_and_push_heap usage demo:\n";
        std::vector<int> v{3, 1, 4, 1, 5, 9};

        std::cout << "initially, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';


        std::make_heap(v.begin(), v.end());

        std::cout << "After make_heap, v: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::pop_heap(v.begin(), v.end()); // 移动最大元素到结尾

        std::cout << "after pop_heap: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        int largest = v.back();
        v.pop_back();  // 实际移出最大元素
        std::cout << "largest element: " << largest << '\n';

        std::cout << "heap without largest: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';


        std::cout << "STL push_back usage demo:\npush_back 6 into v, ";
        v.push_back(6);

        std::cout << "before push_heap: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

        std::push_heap(v.begin(), v.end());

        std::cout << "after push_heap: ";
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';
    };
}
