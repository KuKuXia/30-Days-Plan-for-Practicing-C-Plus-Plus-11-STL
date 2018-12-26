//
// Created by LongXiaJun on 2018/12/26 0026.
//

#include "day20_max_and_max_element.h"
#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_max_and_max_lelment {
    namespace definition {
        // Possible Definition
        template<typename T>
        const T &max(const T &lhs, const T &rhs) {
            return lhs > rhs ? lhs : rhs;
        }

        template<typename T, typename Compare>
        const T &max(const T &a, const T &b, Compare comp) {
            return (comp(a, b)) ? b : a;
        }

        template<typename T>
        T max(std::initializer_list<T> ilist) {
            return *std::max_element(ilist.begin(), ilist.end());
        }

        template<typename T, typename Compare>
        T max(std::initializer_list<T> ilist, Compare comp) {
            return *std::max_element(ilist.begin(), ilist.end(), comp);
        }

        template<typename ForwardIt>
        ForwardIt max_element(ForwardIt first, ForwardIt last) {
            if (first == last) {
                return last;
            }
            ForwardIt largest = first;
            ++first;
            for (; first != last; ++first) {
                if (*largest < *first) {
                    largest = first;
                }
            }
            return largest;
        }

        template<typename ForwardIt, typename Compare>
        ForwardIt max_element(ForwardIt first, ForwardIt last,
                              Compare comp) {
            if (first == last) {
                return last;
            }
            ForwardIt largest = first;
            ++first;
            for (; first != last; ++first) {
                if (comp(*largest, *first)) {
                    largest = first;
                }
            }
            return largest;
        }

    }

    static bool abs_compare(int a, int b) {
        return (std::abs(a) < std::abs(b));
    }

    void stl_max_and_max_element() {
        std::cout << "STL max_and_max_element usage demo: \n";
        std::cout << "larger of 1 and 9999: " << std::max(1,

                                                          9999) << '\n'
                  << "larger of 'a', and 'b': " << std::max('a', 'b') << '\n'
                  << "longest of \"foo\", \"bar\", and \"hello\": " <<
                  std::max({"foo", "bar", "hello"},
                           [](const std::string &s1, const std::string &s2) {
                               return s1.size() < s2.size();
                           }) << '\n';
        std::cout << "STL max_element usage demo:\n";
        std::vector<int> v{3, 1, -14, 1, 5, 9};
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << ' ';
        });
        std::cout << '\n';
        std::vector<int>::iterator result;

        result = std::max_element(v.begin(), v.end());
        std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';

        result = std::max_element(v.begin(), v.end(), abs_compare);
        std::cout << "max element (absolute) at: " << std::distance(v.begin(), result) << "\n";

    }


}