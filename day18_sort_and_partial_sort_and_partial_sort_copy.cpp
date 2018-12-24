//
// Created by LongXiaJun on 2018/12/24 0024.
//

#include "day18_sort_and_partial_sort_and_partial_sort_copy.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>

namespace demo_sort_and_partial_sort_and_partial_sort_copy {


    void stl_sort_and_partial_sort_and_partial_sort_copy() {
        std::cout << "STL sort usage demo: \n";
        std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        std::cout << "The source is: ";
        std::for_each(s.begin(), s.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        // 用默认的 operator< 排序
        std::sort(s.begin(), s.end());
        std::cout << "Sort using the default operator: ";
        for (auto a : s) {
            std::cout << a << " ";
        }
        std::cout << "\nSort using the standord greater:";

        // 用标准库比较函数对象排序
        std::sort(s.begin(), s.end(), std::greater<int>());
        for (auto a : s) {
            std::cout << a << " ";
        }
        std::cout << '\n';

        // 用自定义函数对象排序
        struct {
            bool operator()(int a, int b) const {
                return a < b;
            }
        } customLess;
        std::cout << "Sort using the custom function object: ";
        std::sort(s.begin(), s.end(), customLess);
        for (auto a : s) {
            std::cout << a << " ";
        }
        std::cout << '\n';

        // 用 lambda 表达式排序
        std::cout << "Sort using the lambda function: ";
        std::sort(s.begin(), s.end(), [](int a, int b) {
            return b < a;
        });
        for (auto a : s) {
            std::cout << a << " ";
        }
        std::cout << '\n';

        std::cout << " STL partial_sort usage demo: \n";
        std::array<int, 10> s1{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        std::cout << "The source is: ";
        std::for_each(s1.begin(), s1.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        std::partial_sort(s1.begin(), s1.begin() + 3, s1.end());
        std::cout << "After partial_sort the 3 elements, the source is: \n";
        for (int a : s1) {
            std::cout << a << " ";
        }
        std::cout << std::endl;

        std::vector<int> v0{4, 2, 5, 1, 3};
        std::vector<int> v1{10, 11, 12};
        std::vector<int> v2{10, 11, 12, 13, 14, 15, 16};
        std::vector<int>::iterator it;
        std::cout << "STL partial_sort_copy usage demo: \n";
        std::cout << "The source is: ";
        std::for_each(v0.begin(), v0.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        it = std::partial_sort_copy(v0.begin(), v0.end(), v1.begin(), v1.end());

        std::cout << "Writing to the smaller vector in ascending order gives: ";
        for (int a : v1) {
            std::cout << a << " ";
        }
        std::cout << '\n';
        if (it == v1.end())
            std::cout << "The return value is the end iterator\n";

        it = std::partial_sort_copy(v0.begin(), v0.end(), v2.begin(), v2.end(),
                                    std::greater<int>());

        std::cout << "Writing to the larger vector in descending order gives: ";
        for (int a : v2) {
            std::cout << a << " ";
        }
        std::cout << '\n' << "The return value is the iterator to " << *it << '\n';
    }
}