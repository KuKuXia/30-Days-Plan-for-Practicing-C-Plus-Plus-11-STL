//
// Created by LongXiaJun on 2018/12/26 0026.
//

#include "day20_min_and_min_element.h"

#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_min_and_min_element {
    namespace definition {
        // Possible Definition
        template<typename T>
        const T &min(const T &a, const T &b) {
            return (b < a) ? b : a;
        }

        template<typename T, typename Compare>
        const T &min(const T &a, const T &b, Compare comp) {
            return (comp(b, a)) ? b : a;
        }

        template<typename T>
        T min(std::initializer_list<T> ilist) {
            return *std::min_element(ilist.begin(), ilist.end());
        }

        template<typename T, typename Compare>
        T min(std::initializer_list<T> ilist, Compare comp) {
            return *std::min_element(ilist.begin(), ilist.end(), comp);
        }

        template<typename ForwardIt>
        ForwardIt min_element(ForwardIt first, ForwardIt last) {
            if (first == last) return last;

            ForwardIt smallest = first;
            ++first;
            for (; first != last; ++first) {
                if (*first < *smallest) {
                    smallest = first;
                }
            }
            return smallest;
        }

        template<typename ForwardIt, typename Compare>
        ForwardIt min_element(ForwardIt first, ForwardIt last,
                              Compare comp) {
            if (first == last) return last;

            ForwardIt smallest = first;
            ++first;
            for (; first != last; ++first) {
                if (comp(*first, *smallest)) {
                    smallest = first;
                }
            }
            return smallest;
        }

    }

    void stl_min_and_min_element() {
        std::cout << "STL min usage demo: \n";
        std::cout << "smaller of 1 and 9999: " << std::min(1, 9999) << '\n'
                  << "smaller of 'a', and 'b': " << std::min('a', 'b') << '\n'
                  << "shortest of \"foo\", \"bar\", and \"hello\": " <<
                  std::min({"foo", "bar", "hello"},
                           [](const std::string &s1, const std::string &s2) {
                               return s1.size() < s2.size();
                           }) << '\n';

        std::cout << "STL min_element usage demo: \n";
        std::vector<int> v{3, 1, 4, 1, 5, 9};
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << '\n';
        std::vector<int>::iterator result = std::min_element(std::begin(v), std::end(v));
        std::cout << "min element at: " << std::distance(std::begin(v), result) << '\n';

    }
}