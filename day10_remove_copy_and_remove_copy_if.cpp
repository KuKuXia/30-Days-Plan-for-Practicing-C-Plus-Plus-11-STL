//
// Created by LongXiaJun on 2018/12/16 0016.
//

#include "day10_remove_copy_and_remove_copy_if.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


namespace demo_remove_copy_and_remove_copy_if {
    namespace definition {
        //Possible definition
        template<typename InputIt, typename OutputIt, typename T>
        OutputIt remove_copy(InputIt first, InputIt last,
                             OutputIt d_first, const T &value) {
            for (; first != last; ++first) {
                if (!(*first == value)) {
                    *d_first++ = *first;
                }
            }
            return d_first;
        }

        template<typename InputIt, typename OutputIt, typename UnaryPredicate>
        OutputIt remove_copy_if(InputIt first, InputIt last,
                                OutputIt d_first, UnaryPredicate p) {
            for (; first != last; ++first) {
                if (!p(*first)) {
                    *d_first++ = *first;
                }
            }
            return d_first;
        }
    }

    void stl_remove_copy_and_remove_copy_if() {
        std::cout << "STL remove_copy and remove_copy_if usage demo: \n";
        std::string str = "Text with some   spaces";
        std::cout << "before remove_copy, the str is: " << str << "\n";

        std::cout << "after remove_copy, the str is:  ";
        std::remove_copy(str.begin(), str.end(),
                         std::ostream_iterator<char>(std::cout), ' ');
        std::cout << '\n';

    }
}