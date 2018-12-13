//
// Created by LongXiaJun on 2018/12/13 0013.
//

#include "day7_copy_and_copy_if.h"
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>


namespace demo_copy_and_copy_if {
    namespace definition {
        //Possible definition
        template<typename InputIt, typename OutputIt>
        OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
            while (first != last) {
                *d_first++ = *first++;
            }
            return d_first;
        }

        template<typename InputIt, typename OutputIt, class UnaryPredicate>
        OutputIt copy_if(InputIt first, InputIt last,
                         OutputIt d_first, UnaryPredicate pred) {
            while (first != last) {
                if (pred(*first))
                    *d_first++ = *first;
                ++first;
            }
            return d_first;
        }

    }

    void stl_copy_and_copy_if() {
        std::cout << "STL copy_and_copy_if usage demo: \n";
        std::vector<int> from_vector(10);
        std::iota(from_vector.begin(), from_vector.end(), 0);
        std::cout << "The from_vector is: ";
        std::for_each(from_vector.begin(), from_vector.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << std::endl;
        std::vector<int> to_vector(10);

        std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
//        std::copy_n(from_vector.begin(), 5, to_vector.begin());
        std::cout << "After copy the to_vector is: ";
        std::for_each(to_vector.begin(), to_vector.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << std::endl;
        std::cout << "The to_vector is using std::ostream_iterator: \n";
        std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

    }


}