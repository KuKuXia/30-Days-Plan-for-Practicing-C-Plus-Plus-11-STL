//
// Created by LongXiaJun on 2018/12/17 0017.
//

#include "day11_replace_copy_and_replace_copy_if.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


namespace demo_replace_copy_and_replace_copy_if {
    namespace definition {
        //Possible definition
        template<typename InputIt, typename OutputIt, typename T>
        OutputIt replace_copy(InputIt first, InputIt last, OutputIt d_first,
                              const T &old_value, const T &new_value) {
            for (; first != last; ++first) {
                *d_first++ = (*first == old_value) ? new_value : *first;
            }
            return d_first;
        }

        template<typename InputIt, typename OutputIt,
                typename UnaryPredicate, typename T>
        OutputIt replace_copy_if(InputIt first, InputIt last, OutputIt d_first,
                                 UnaryPredicate p, const T &new_value) {
            for (; first != last; ++first) {
                *d_first++ = p(*first) ? new_value : *first;
            }
            return d_first;
        }
    }

    void stl_replace_copy_and_replace_copy_if() {
        std::cout << "STL replace_copy and replace_copy_if usage demo: \n";
        std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << "\nAfter replace_copy the num > 5 with 99,  output is: " << std::endl;
        std::replace_copy_if(v.begin(), v.end(),
                             std::ostream_iterator<int>(std::cout, " "),
                             [](int n) { return n > 5; }, 99);
        std::cout << '\n';
    }

}