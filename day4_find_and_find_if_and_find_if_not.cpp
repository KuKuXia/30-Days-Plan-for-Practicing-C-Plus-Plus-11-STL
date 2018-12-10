//
// Created by LongXiaJun on 2018/12/10 0010.
//

#include <iostream>
#include <vector>
#include "algorithm"
#include "day4_find_and_find_if_and_find_if_not.h"


namespace demo_find_and_find_if_and_find_if_not {
    namespace definition {
        // Possible definition
        template<typename InputIt, typename T>
        InputIt find(InputIt first, InputIt last, const T &value) {
            for (; first != last; ++first) {  //尽量使用前置式
                if (*first == value) return first;
            }
            return last;
        }

        template<typename InputIt, typename UnaryPredicate>
        InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
            for (; first != last; ++first) {
                if (p(*first)) {
                    return first;
                }
            }
            return last;
        }


        template<typename InputIt, typename UnaryPredicate>
        InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q) {
            for (; first != last; ++first) {
                if (!q(*first)) {
                    return first;
                }
            }
            return last;
        }

    }

    void stl_find_and_find_if_and_find_if_not() {
        std::cout << "STL find_and_find_if_and_find_if_not usage demo: " << std::endl;
        int target1 = 3;
        int target2 = 9;

        std::vector<int> nums{1, 2, 3, 4, 5};
        std::cout << "Nums: ";
        std::for_each(nums.begin(), nums.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;

        if (auto result_1 = std::find(nums.begin(), nums.end(), target1);result_1 != nums.end()) {
            std::cout << "Find the " << target1 << " at " << std::distance(nums.begin(),result_1) << std::endl;
        } else {
            std::cout << "Can't find the target " << target1 << std::endl;
        };
        if (auto result_1 = std::find(nums.begin(), nums.end(), target2);result_1 != nums.end()) {
            std::cout << "Find the " << target1 << " at " << std::distance(nums.begin(),result_1) << std::endl;
        } else {
            std::cout << "Can't find the target " << target2 << std::endl;
        };


        if (auto result_1 = std::find_if(nums.begin(), nums.end(), [](auto const &a) { return a % 4 == 0; });result_1 !=
                                                                                                             nums.end()) {
            std::cout << "Find " << *result_1<< " can be divided by 4" << " at " << std::distance(nums.begin(),result_1)
                       << std::endl;
        } else {
            std::cout << "Can't find the num which can be divided by 4 " << std::endl;
        };


        if (auto result_1 = std::find_if_not(nums.begin(), nums.end(), [](auto const &a) { return a < 5; });result_1 !=
                                                                                                            nums.end()) {
            std::cout << "Find " << *result_1 << " which is't less than 5" << " at " << std::distance(result_1, nums.begin())
                       << std::endl;
        } else {
            std::cout << "Can't find num which is less than 5 " << target2 << std::endl;
        };


    }


}


