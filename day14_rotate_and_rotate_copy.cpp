//
// Created by LongXiaJun on 2018/12/20 0020.
//

#include "day14_rotate_and_rotate_copy.h"
#include <vector>
#include <algorithm>
#include <iostream>


namespace demo_rotate_and_rotate_copy {
    namespace definition {
        // Possible Definition
        template<class ForwardIt>
        ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last) {
            if (first == n_first) return last;
            if (n_first == last) return first;

            auto read = n_first;
            auto write = first;
            auto next_read = first; // "read" 撞击 "last" 时的读取位置

            while (read != last) {
                if (write == next_read) next_read = read; // 跟踪 "first" 所至
                std::iter_swap(write++, read++);
            }

            // 旋转剩余序列到位置中
            (rotate)(write, next_read, last);
            return write;
        }

        template<class ForwardIt, class OutputIt>
        OutputIt rotate_copy(ForwardIt first, ForwardIt n_first,
                             ForwardIt last, OutputIt d_first) {
            d_first = std::copy(n_first, last, d_first);
            return std::copy(first, n_first, d_first);
        }

    }


    void stl_rotate_and_rotate_copy() {
        std::cout << "STL rotate and rotate_copy usage demo: \n";

        std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};

        std::cout << "before sort:      ";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // 插入排序
        for (auto i = v.begin(); i != v.end(); ++i) {
            std::rotate(std::upper_bound(v.begin(), i, *i), i, i + 1);
        }

        std::cout << "after sort:       ";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // 简单地旋转到左侧
        std::rotate(v.begin(), v.begin() + 1, v.end());

        std::cout << "simple rotate left  : ";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';

        // 简单地旋转到右侧
        std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

        std::cout << "simple rotate right : ";
        for (int n: v)
            std::cout << n << ' ';
        std::cout << '\n';


        std::vector<int> src = {1, 2, 3, 4, 5};
        std::cout << "The src is: \n";
        for (int n: src)
            std::cout << n << ' ';
        std::cout << '\n';

        auto pivot = std::find(src.begin(), src.end(), 3);
        std::vector<int> dest(src.size());

        std::rotate_copy(src.begin(), pivot, src.end(), dest.begin());
        std::cout << "After copy, the src is: \n";
        for (const auto &i : dest) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}