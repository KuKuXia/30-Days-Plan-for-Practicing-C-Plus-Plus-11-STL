//
// Created by LongXiaJun on 2018/12/9 0009.
//

#include "day3_count_and_count_if.h"
#include <iostream>
#include <algorithm>
#include <vector>


namespace demo_count_and_count_if {
    namespace definition_count_and_count_if {
        // Possible Definition
        template<typename InputIt, typename T>
        typename __gnu_cxx::iterator_traits<InputIt>::difference_type
        count(InputIt first, InputIt last, const T &value) {
            typename __gnu_cxx::iterator_traits<InputIt>::difference_type ret = 0;
            for (; first != last; ++first) {
                if (*first == value) {
                    ret++;
                }
            }
            return ret;
        }

        template<class InputIt, class UnaryPredicate>
        typename __gnu_cxx::iterator_traits<InputIt>::difference_type
        count_if(InputIt first, InputIt last, UnaryPredicate p) {
            typename __gnu_cxx::iterator_traits<InputIt>::difference_type ret = 0;
            for (; first != last; ++first) {
                if (p(*first)) {
                    ret++;
                }
            }
            return ret;
        }

    }

    void stl_count_and_count_if() {

        std::vector<int> v{1, 2, 3, 4, 5, 5, 6, 3, 3, 3, 6, 5, 5, 5, 5, 3, 3, 5, 7, 7, 3, 4,};

        std::cout << "STL count_and_count_if usage demo: " << std::endl;
        std::cout << "Source vector: ";
        std::for_each(v.begin(), v.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        int target1 = 3;
        int target2 = 5;
        int num_target1 = std::count(v.begin(), v.end(), target1);
        int num_target2 = std::count(v.begin(), v.end(), target2);
        std::cout << "Num for " << target1 << " is: " << num_target1 << std::endl;
        std::cout << "Num for " << target2 << " is: " << num_target2 << std::endl;

        int num_item3 = std::count_if(v.begin(), v.end(), [](auto const &a) { return a % 3 == 0; });
        std::cout << "Num of being divided by 3: " << num_item3 << std::endl;

    }


}