//
// Created by LongXiaJun on 2018/12/27 0027.
//

#include "day21_minmax_and_minmax_element.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>

namespace demo_minmax_and_minmax_element {
    namespace definition {
        // Possible Definition
        template<typename ForwardIt, typename Compare>
        std::pair<ForwardIt, ForwardIt>
        minmax_element(ForwardIt first, ForwardIt last, Compare comp) {
            std::pair<ForwardIt, ForwardIt> result(first, first);

            if (first == last) return result;
            if (++first == last) return result;

            if (comp(*first, *result.first)) {
                result.first = first;
            } else {
                result.second = first;
            }
            while (++first != last) {
                ForwardIt i = first;
                if (++first == last) {
                    if (comp(*i, *result.first)) result.first = i;
                    else if (!(comp(*i, *result.second))) result.second = i;
                    break;
                } else {
                    if (comp(*first, *i)) {
                        if (comp(*first, *result.first)) result.first = first;
                        if (!(comp(*i, *result.second))) result.second = i;
                    } else {
                        if (comp(*i, *result.first)) result.first = i;
                        if (!(comp(*first, *result.second))) result.second = first;
                    }
                }
            }
            return result;
        }

        template<typename T>
        std::pair<const T &, const T &> minmax(const T &a, const T &b) {
            return (b < a) ? std::pair<const T &, const T &>(b, a)
                           : std::pair<const T &, const T &>(a, b);
        }

        template<typename T, typename Compare>
        std::pair<const T &, const T &> minmax(const T &a, const T &b, Compare comp) {
            return comp(b, a) ? std::pair<const T &, const T &>(b, a)
                              : std::pair<const T &, const T &>(a, b);
        }

        template<typename T>
        std::pair<T, T> minmax(std::initializer_list<T> ilist) {
            auto p = std::minmax_element(ilist.begin(), ilist.end());
            return std::make_pair(*p.first, *p.second);
        }

        template<typename T, typename Compare>
        std::pair<T, T> minmax(std::initializer_list<T> ilist, Compare comp) {
            auto p = std::minmax_element(ilist.begin(), ilist.end(), comp);
            return std::make_pair(*p.first, *p.second);
        }


    }

    void stl_minmax_and_minmax_element() {
        std::cout << "STL minmax usage demo: \n";
        std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};
        std::srand(std::time(0));
        std::cout << "The source vector is:\n";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << ' ';
        });
        std::cout << '\n';

        std::pair<int, int> bounds = std::minmax(std::rand() % v.size(),
                                                 std::rand() % v.size());

        std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
        for (int i = bounds.first; i < bounds.second; ++i) {
            std::cout << v[i] << ' ';
        }
        std::cout << '\n';

        std::cout << "STL minmax_element usage demo:\n";
        auto result = std::minmax_element(v.begin(), v.end());
        std::cout << "min element at: " << (result.first - v.begin()) << '\n';
        std::cout << "max element at: " << (result.second - v.begin()) << '\n';
    }
}