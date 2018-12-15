//
// Created by LongXiaJun on 2018/12/15 0015.
//

#include "day9_transform.h"
#include <vector>
#include <algorithm>
#include <iostream>


namespace demo_transform {
    namespace definition {
        // Possible definition
        template<typename InputIt, typename OutputIt, typename UnaryOperation>
        OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op) {
            while (first1 != last1) {
                *d_first++ = unary_op(*first1++);
            }
            return d_first;
        }
    }

    template<typename InputIt1, typename InputIt2,
            typename OutputIt, typename BinaryOperation>
    OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                       OutputIt d_first, BinaryOperation binary_op) {
        while (first1 != last1) {
            *d_first++ = binary_op(*first1++, *first2++);
        }
        return d_first;
    }

    void stl_transform() {
        std::cout << "STL transform usage damo: \n";
        std::string s("hello");
        std::cout << "Source string is: " << s << std::endl;
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) -> unsigned char { return std::toupper(c); });

        std::vector<std::size_t> ordinals;
        std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
                       [](unsigned char c) -> std::size_t { return c; });

        std::cout << "After transform to toupper. the source is: " << s
                  << "\nAfter transform. the ASCII of each char is: ";

        for (auto ord : ordinals) {
            std::cout << ' ' << ord;
        }
        std::cout << std::endl;

    }


}
