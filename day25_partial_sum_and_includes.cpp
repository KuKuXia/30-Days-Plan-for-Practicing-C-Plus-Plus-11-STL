//
// Created by LongXiaJun on 2018/12/31 0031.
//

#include "day25_partial_sum_and_includes.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iterator>


namespace demo_partial_sum_and_includes {
    namespace definition {
        // Possible definition

        template<typename InputIt, typename OutputIt>
        OutputIt partial_sum(InputIt first, InputIt last,
                             OutputIt d_first) {
            if (first == last) return d_first;

            typename std::iterator_traits<InputIt>::value_type sum = *first;
            *d_first = sum;

            while (++first != last) {
                sum = std::move(sum) + *first; // C++20 起有 std::move
                *++d_first = sum;
            }
            return ++d_first;

            // 或 C++14 起：
            // return std::partial_sum(first, last, d_first, std::plus<>());
        }

        template<typename InputIt, typename OutputIt, typename BinaryOperation>
        OutputIt partial_sum(InputIt first, InputIt last,
                             OutputIt d_first, BinaryOperation op) {
            if (first == last) return d_first;

            typename std::iterator_traits<InputIt>::value_type sum = *first;
            *d_first = sum;

            while (++first != last) {
                sum = op(std::move(sum), *first); // C++20 起有 std::move
                *++d_first = sum;
            }
            return ++d_first;
        }

        template<typename InputIt1, typename InputIt2>
        bool includes(InputIt1 first1, InputIt1 last1,
                      InputIt2 first2, InputIt2 last2) {
            for (; first2 != last2; ++first1) {
                if (first1 == last1 || *first2 < *first1)
                    return false;
                if (!(*first1 < *first2))
                    ++first2;
            }
            return true;
        }

        template<typename InputIt1, typename InputIt2, typename Compare>
        bool includes(InputIt1 first1, InputIt1 last1,
                      InputIt2 first2, InputIt2 last2, Compare comp) {
            for (; first2 != last2; ++first1) {
                if (first1 == last1 || comp(*first2, *first1))
                    return false;
                if (!comp(*first1, *first2))
                    ++first2;
            }
            return true;
        }


    }

    void stl_partial_sum_and_includes() {
        std::cout << "STL partial_sum usage demo:\n";
        std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // 或 std::vector<int>v(10, 2);

        std::cout << "The first 10 even numbers are: ";
        std::partial_sum(v.begin(), v.end(),
                         std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';

        std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
        std::cout << "The first 10 powers of 2 are: ";
        for (auto n : v) {
            std::cout << n << " ";
        }
        std::cout << '\n';


        std::vector<char> v1{'a', 'b', 'c', 'f', 'h', 'x'};
        std::vector<char> v2{'a', 'b', 'c'};
        std::vector<char> v3{'a', 'c'};
        std::vector<char> v4{'g'};
        std::vector<char> v5{'a', 'c', 'g'};

        std::cout << "STL includes usage demo:\n";
        for (auto i : v1) std::cout << i << ' ';
        std::cout << "\nincludes:\n" << std::boolalpha;

        for (auto i : v2) std::cout << i << ' ';
        std::cout << ": " << std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n';
        for (auto i : v3) std::cout << i << ' ';
        std::cout << ": " << std::includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << '\n';
        for (auto i : v4) std::cout << i << ' ';
        std::cout << ": " << std::includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << '\n';
        for (auto i : v5) std::cout << i << ' ';
        std::cout << ": " << std::includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << '\n';

        auto cmp_nocase = [](char a, char b) {
            return std::tolower(a) < std::tolower(b);
        };

        std::vector<char> v6{'A', 'B', 'C'};
        for (auto i : v6) std::cout << i << ' ';
        std::cout << ": (case-insensitive) "
                  << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end(), cmp_nocase)
                  << '\n';
    }


}