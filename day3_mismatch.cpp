//
// Created by LongXiaJun on 2018/12/9 0009.
//

#include "day3_mismatch.h"
#include <iostream>
#include <algorithm>
#include <vector>


namespace demo_mismatch {

    namespace definition_mismatch {
        // Possible definition
        template<typename InputIt1, typename InputIt2>
        std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 lasst1, InputIt2 first2) {
            while (first1 != lasst1 && *first1 == *first2) {
                ++first1, ++first2;
            }
            return std::make_pair(first1, first2);
        }

        template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
        std::pair<InputIt1, InputIt2>
        mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
            while (first1 != last1 && p(*first1, *first2)) {
                ++first1, ++first2;
            }
            return std::make_pair(first1, first2);
        }


        template<typename InputIt1, typename InputIt2>
        std::pair<InputIt1, InputIt2>
        mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
            while (first1 != last1 && first2 != last2 && *first1 == *first2) {
                ++first1, ++first2;
            }
            return std::make_pair(first1, first2);
        }

        template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
        std::pair<InputIt1, InputIt2>
        mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPredicate p) {
            while (first1 != last1 && first2 != last2 && p(*first1, *first2)) {
                ++first1, ++first2;
            }
            return std::make_pair(first1, first2);
        }

    }

    // 此程序确定同时在给定字符串起始与在其结尾按逆序同时找到的最长子串（可能重叠）。
    std::string mirror_ends(const std::string &in) {
        return std::string(in.begin(), std::mismatch(in.begin(), in.end(), in.rbegin()).first);
    }

    void stl_mismatch() {
        std::cout << "STL mismatch usage demo: " << std::endl;
        std::cout << "the mirror_ends for abxyzba is: "  <<mirror_ends("abXYZba") << '\n' << "the mirror_ends for abca is: "<< mirror_ends("abca") << '\n' << "the mirror_ends for abaababa is: "<<mirror_ends("abaababa")
                  << std::endl;
    }

}