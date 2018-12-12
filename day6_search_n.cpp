//
// Created by LongXiaJun on 2018/12/12 0012.
//

#include "day6_search_n.h"
#include <iostream>
#include <algorithm>
#include <vector>


namespace demo_search_n {
    namespace definition {
        //Possible definition
        template<typename ForwardIt, typename Size, typename T>
        ForwardIt search_n(ForwardIt first, ForwardIt last,
                           Size count, const T &value) {
            for (; first != last; ++first) {
                if (!(*first == value)) {
                    continue;
                }

                ForwardIt candidate = first;
                Size cur_count = 0;

                while (true) {
                    ++cur_count;
                    if (cur_count == count) {
                        // 成功
                        return candidate;
                    }
                    ++first;
                    if (first == last) {
                        // 穷尽列表
                        return last;
                    }
                    if (!(*first == value)) {
                        // 栏中过少
                        break;
                    }
                }
            }
            return last;
        }

        template<typename ForwardIt, typename Size, typename T, typename BinaryPredicate>
        ForwardIt search_n(ForwardIt first, ForwardIt last,
                           Size count, const T &value, BinaryPredicate p) {
            for (; first != last; ++first) {
                if (!p(*first, value)) {
                    continue;
                }

                ForwardIt candidate = first;
                Size cur_count = 0;

                while (true) {
                    ++cur_count;
                    if (cur_count == count) {
                        // 成功
                        return candidate;
                    }
                    ++first;
                    if (first == last) {
                        // 穷尽列表
                        return last;
                    }
                    if (!p(*first, value)) {
                        // 栏中过少
                        break;
                    }
                }
            }
            return last;
        }

    }

    template<class Container, class Size, class T>
    bool consecutive_values(const Container &c, Size count, const T &v) {
        return std::search_n(std::begin(c), std::end(c), count, v) != std::end(c);
    }

    void stl_search_n() {
        std::cout << "STL search_n usage demo: " << std::endl;
        const char sequence[] = "1001010100010101001010101";
        std::cout << "The original source is: " << sequence << std::endl;
        std::cout << std::boolalpha;
        std::cout << "Has 4 consecutive zeros: "
                  << consecutive_values(sequence, 4, '0') << '\n';
        std::cout << "Has 3 consecutive zeros: "
                  << consecutive_values(sequence, 3, '0') << '\n';

    };


}

