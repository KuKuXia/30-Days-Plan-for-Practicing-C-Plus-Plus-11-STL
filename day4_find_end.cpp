//
// Created by LongXiaJun on 2018/12/10 0010.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "day4_find_end.h"

namespace demo_find_end {
    namespace definition {
        // Possible definition
        template<typename ForwardIt1, typename ForwardIt2>
        ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last) {
            if (s_first == s_last)return last;
            ForwardIt1 result = last;
            while (true) {
                ForwardIt1 new_result = std::search(first, last, s_first, s_last);
                if (new_result == last) {
                    break;
                } else {
                    result = new_result;
                    first = result;
                    ++first;
                }
            }
            return result;
        }

        template<typename ForwardIt1, typename ForwardIt2, typename BinaryPredicate>
        ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                            ForwardIt2 s_first, ForwardIt2 s_last,
                            BinaryPredicate p) {
            if (s_first == s_last)
                return last;
            ForwardIt1 result = last;
            while (true) {
                ForwardIt1 new_result = std::search(first, last, s_first, s_last, p);
                if (new_result == last) {
                    break;
                } else {
                    result = new_result;
                    first = result;
                    ++first;
                }
            }
            return result;
        }
    }

    void stl_find_end() {
        std::cout << "STL find_end usage demo: " << std::endl;
        int target1 = 3;
        int target2 = 9;

        std::vector<int> nums{1, 2, 3, 4, 5, 4, 8, 9, 3, 4, 5, 5, 7, 8, 7, 7,};
        std::vector<int> subsequence{7, 8};
        std::cout << "Nums: ";
        std::for_each(nums.begin(), nums.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;
        std::cout << "Subsequence: ";
        std::for_each(subsequence.begin(), subsequence.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;


        if (auto result = std::find_end(nums.begin(), nums.end(), subsequence.begin(), subsequence.end()); result !=
                                                                                                           nums.end()) {
            std::cout << "Find the last subsequence at " << std::distance(nums.begin(), result) << std::endl;
        }else
        {
            std::cout << "Cann't find the subsequence." << std::endl;
        }

        subsequence.push_back(9);
        std::cout << "Now Subsequence: ";
        std::for_each(subsequence.begin(), subsequence.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;


        if (auto result = std::find_end(nums.begin(), nums.end(), subsequence.begin(), subsequence.end()); result !=
                                                                                                           nums.end()) {
            std::cout << "Find the last subsequence at " << std::distance(nums.begin(), result) << std::endl;
        }
        {
            std::cout << "Cann't find the subsequence." << std::endl;
        }

    }
}