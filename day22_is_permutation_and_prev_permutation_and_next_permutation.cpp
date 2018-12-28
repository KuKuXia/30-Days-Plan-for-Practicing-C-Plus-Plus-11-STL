//
// Created by LongXiaJun on 2018/12/28 0028.
//

#include "day22_is_permutation_and_prev_permutation_and_next_permutation.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

namespace demo_is_permutation_and_prev_permutation_and_next_permutation {
    namespace definition {
        // Possible definition
        template<typename ForwardIt1, typename ForwardIt2>
        bool is_permutation(ForwardIt1 first, ForwardIt1 last,
                            ForwardIt2 d_first) {
            // 跳过公共前缀
            std::tie(first, d_first) = std::mismatch(first, last, d_first);
            // 在 rest 上迭代，计数 [d_first, d_last) 中出现多少次
            // 每个来自 [first, last) 的元素
            if (first != last) {
                ForwardIt2 d_last = d_first;
                std::advance(d_last, std::distance(first, last));
                for (ForwardIt1 i = first; i != last; ++i) {
                    if (i != std::find(first, i, *i)) continue; // 已经遇到此 *i

                    auto m = std::count(d_first, d_last, *i);
                    if (m == 0 || std::count(i, last, *i) != m) {
                        return false;
                    }
                }
            }
            return true;
        }

        template<typename BidirIt>
        bool next_permutation(BidirIt first, BidirIt last) {
            if (first == last) return false;
            BidirIt i = last;
            if (first == --i) return false;

            while (true) {
                BidirIt i1, i2;

                i1 = i;
                if (*--i < *i1) {
                    i2 = last;
                    while (!(*i < *--i2));
                    std::iter_swap(i, i2);
                    std::reverse(i1, last);
                    return true;
                }
                if (i == first) {
                    std::reverse(first, last);
                    return false;
                }
            }
        }

        template<typename BidirIt>
        bool prev_permutation(BidirIt first, BidirIt last) {
            if (first == last) return false;
            BidirIt i = last;
            if (first == --i) return false;

            while (1) {
                BidirIt i1, i2;

                i1 = i;
                if (*i1 < *--i) {
                    i2 = last;
                    while (!(*--i2 < *i));
                    std::iter_swap(i, i2);
                    std::reverse(i1, last);
                    return true;
                }
                if (i == first) {
                    std::reverse(first, last);
                    return false;
                }
            }
        }


    }

    void stl_is_permutation_and_prev_permutation_and_next_permutation() {
        std::cout << "STL is_permutation usage demo: \n";
        std::vector<int> v1{1, 2, 3, 4, 5};
        std::vector<int> v2{3, 5, 4, 1, 2};
        std::cout << "3,5,4,1,2 is a permutation of 1,2,3,4,5? "
                  << std::boolalpha
                  << std::is_permutation(v1.begin(), v1.end(), v2.begin()) << '\n';

        std::vector<int> v3{3, 5, 4, 1, 1};
        std::cout << "3,5,4,1,1 is a permutation of 1,2,3,4,5? "
                  << std::boolalpha
                  << std::is_permutation(v1.begin(), v1.end(), v3.begin()) << '\n';

        std::cout << "STL next_permutation usage demo:\n";
        std::string s = "aba";
        std::sort(s.begin(), s.end());
        do {
            std::cout << s << '\n';
        } while (std::next_permutation(s.begin(), s.end()));

        std::cout << "STL prev_permutation usage demo:\n";

        std::sort(s.begin(), s.end(), std::greater<char>());
        do {
            std::cout << s << '\n';
        } while (std::prev_permutation(s.begin(), s.end()));
        std::cout << '\n';


    }

}