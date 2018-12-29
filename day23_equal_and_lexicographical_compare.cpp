//
// Created by LongXiaJun on 2018/12/29 0029.
//

#include "day23_equal_and_lexicographical_compare.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

namespace demo_equal_and_lexicographical_compare {
    namespace definition {
        //Possible definition
        template<typename InputIt1, typename InputIt2>
        bool equal(InputIt1 first1, InputIt1 last1,
                   InputIt2 first2) {
            for (; first1 != last1; ++first1, ++first2) {
                if (!(*first1 == *first2)) {
                    return false;
                }
            }
            return true;
        }

        template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
        bool equal(InputIt1 first1, InputIt1 last1,
                   InputIt2 first2, BinaryPredicate p) {
            for (; first1 != last1; ++first1, ++first2) {
                if (!p(*first1, *first2)) {
                    return false;
                }
            }
            return true;
        }

        template<typename InputIt1, typename InputIt2>
        bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                     InputIt2 first2, InputIt2 last2) {
            for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
                if (*first1 < *first2) return true;
                if (*first2 < *first1) return false;
            }
            return (first1 == last1) && (first2 != last2);
        }

        template<typename InputIt1, typename InputIt2, typename Compare>
        bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                     InputIt2 first2, InputIt2 last2,
                                     Compare comp) {
            for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
                if (comp(*first1, *first2)) return true;
                if (comp(*first2, *first1)) return false;
            }
            return (first1 == last1) && (first2 != last2);
        }


    }

    // 测试字符串是否为回文
    void test(const std::string &s) {
        if (std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin())) {
            std::cout << "\"" << s << "\" is a palindrome\n";
        } else {
            std::cout << "\"" << s << "\" is not a palindrome\n";
        }
    }

    void stl_equal_and_lexicographical_compare() {
        std::cout << "STL equal usage demo: \n";
        test("radar");
        test("hello");

        std::cout << "STL lexicographical_compare usage demo: \n";
        std::vector<char> v1{'a', 'b', 'c', 'd'};
        std::vector<char> v2{'a', 'b', 'c', 'd'};

        std::mt19937 g{std::random_device{}()};
        while (!std::lexicographical_compare(v1.begin(), v1.end(),
                                             v2.begin(), v2.end())) {
            for (auto c : v1) std::cout << c << ' ';
            std::cout << ">= ";
            for (auto c : v2) std::cout << c << ' ';
            std::cout << '\n';

            std::shuffle(v1.begin(), v1.end(), g);
            std::shuffle(v2.begin(), v2.end(), g);
        }

        for (auto c : v1) std::cout << c << ' ';
        std::cout << "< ";
        for (auto c : v2) std::cout << c << ' ';
        std::cout << '\n';

    }


}