//
// Created by LongXiaJun on 2018/12/30 0030.
//

#include "day24_inner_product_and_adjacent_difference.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace demo_inner_product_and_adjacent_difference {
    namespace definition {
        // Possible definition
        template<typename InputIt1, typename InputIt2, typename T>
        T inner_product(InputIt1 first1, InputIt1 last1,
                        InputIt2 first2, T init) {
            while (first1 != last1) {
                init = std::move(init) + *first1 * *first2; // C++20 起有 std::move
                ++first1;
                ++first2;
            }
            return init;
        }

        template<typename InputIt1, typename InputIt2,
                typename T,
                typename BinaryOperation1, typename BinaryOperation2>
        T inner_product(InputIt1 first1, InputIt1 last1,
                        InputIt2 first2, T init,
                        BinaryOperation1 op1,
                        BinaryOperation2 op2) {
            while (first1 != last1) {
                init = op1(std::move(init), op2(*first1, *first2)); // C++20 起有 std::move
                ++first1;
                ++first2;
            }
            return init;
        }

        template<typename InputIt, typename OutputIt>
        OutputIt adjacent_difference(InputIt first, InputIt last,
                                     OutputIt d_first) {
            if (first == last) return d_first;

            typedef typename std::iterator_traits<InputIt>::value_type value_t;
            value_t acc = *first;
            *d_first = acc;
            while (++first != last) {
                value_t val = *first;
                *++d_first = val - std::move(acc); // C++20 起有 std::move
                acc = std::move(val);
            }
            return ++d_first;
        }

        template<typename InputIt, typename OutputIt, typename BinaryOperation>
        OutputIt adjacent_difference(InputIt first, InputIt last,
                                     OutputIt d_first, BinaryOperation op) {
            if (first == last) return d_first;

            typedef typename std::iterator_traits<InputIt>::value_type value_t;
            value_t acc = *first;
            *d_first = acc;
            while (++first != last) {
                value_t val = *first;
                *++d_first = op(val, std::move(acc)); // C++20 起有 std::move
                acc = std::move(val);
            }
            return ++d_first;
        }


    }

    void stl_inner_product_and_adjacent_difference() {
        std::cout << "STL inner_product usage demo:\n";

        std::vector<int> a{0, 1, 2, 3, 4};
        std::vector<int> b{5, 4, 2, 3, 1};

        int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);

        std::cout << "Inner product of a and b: " << r1 << '\n';

        int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0,
                                    std::plus<>(), std::equal_to<>());
        std::cout << "Number of pairwise matches between a and b: " << r2 << '\n';

        std::cout << "STL adjacent_difference usage demo:\n";

        // 默认实现——二个项之间的差

        std::vector<int> v{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        std::adjacent_difference(v.begin(), v.end(), v.begin());

        for (auto n : v) {
            std::cout << n << ' ';
        }
        std::cout << '\n';

        // 斐波那契
        // 注意，列表中下一项是当前迭代的结果

        v = std::vector<int>(10);
        v[0] = 1;

        std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<int>());

        for (auto n : v) {
            std::cout << n << ' ';
        }
        std::cout << '\n';

    }
}