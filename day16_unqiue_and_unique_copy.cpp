//
// Created by LongXiaJun on 2018/12/22 0022.
//

#include "day16_unqiue_and_unique_copy.h"
#include <vector>
#include <algorithm>
#include <iostream>


namespace demo_unique_and_unique_copy {
    namespace definition {
        template<class ForwardIt>
        ForwardIt unique(ForwardIt first, ForwardIt last) {
            if (first == last)
                return last;

            ForwardIt result = first;
            while (++first != last) {
                if (!(*result == *first) && ++result != first) {
                    *result = std::move(*first);
                }
            }
            return ++result;
        }

        template<class ForwardIt, class BinaryPredicate>
        ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPredicate p) {
            if (first == last)
                return last;

            ForwardIt result = first;
            while (++first != last) {
                if (!p(*result, *first) && ++result != first) {
                    *result = std::move(*first);
                }
            }
            return ++result;
        }
    }

    void stl_unique_and_unique_copy() {
        std::cout << "STL unique and unique_copy usage demo: \n";
        // 移除重复元素
        std::vector<int> v{1, 2, 3, 1, 2, 3, 3, 4, 5, 4, 5, 6, 7};
        std::cout << "The source vector is: ";
        for (int i : v)
            std::cout << i << " ";
        std::cout << "\n";
        std::sort(v.begin(), v.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7
        auto last = std::unique(v.begin(), v.end());
        // v 现在保有 {1 2 3 4 5 6 7 x x x x x x} ，其中 x 不确定
        v.erase(last, v.end());
        std::cout << "After unique operation, the vector is: ";
        for (int i : v)
            std::cout << i << " ";
        std::cout << "\n";


        std::string s1 = "The      string    with many       spaces!";
        std::cout << "Before unique_copy, the source string is: " << s1 << '\n';

        std::string s2;
        std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                         [](char c1, char c2) { return c1 == ' ' && c2 == ' '; });

        std::cout << "After unique_copy, the s2 is: " << s2 << '\n';

    }
}