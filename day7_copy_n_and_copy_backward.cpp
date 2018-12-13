//
// Created by LongXiaJun on 2018/12/13 0013.
//

#include "day7_copy_n_and_copy_backward.h"
#include <vector>
#include <algorithm>
#include <iostream>


namespace demo_copy_n_and_copy_backward {
    //Possible definition
    namespace definition {
        template<typename InputIt, typename Size, typename OutputIt>
        OutputIt copy_n(InputIt first, Size count, OutputIt result) {
            if (count > 0) {
                *result++ = *first;
                for (Size i = 1; i < count; ++i) {
                    *result++ = *++first;
                }
            }
            return result;
        }

    }

    template<typename BidirIt1, typename BidirIt2>
    BidirIt2 copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last) {
        while (first != last) {
            *(--d_last) = *(--last);
        }
        return d_last;
    }

    void stl_copy_n_and_copy_backward() {
        std::cout << "STL copy_n and copy_backward usage demo: \n";
        std::string in = "123245436456";
        std::string out;
        std::cout << "The in string is: " << in << std::endl;
        int n = 5;
        std::copy_n(in.begin(), n, std::back_inserter(out));
        std::cout << "After copy " << n << " elements. The out is: " << out << std::endl;

        std::cout << "STL copy_backward usage demo is: \n";
        std::vector<int> from_vector;
        for (int i = 0; i < 10; i++) {
            from_vector.push_back(i);
        }
        std::cout << "The from_vector is: ";
        std::for_each(from_vector.begin(), from_vector.end(), [](auto const &i) {
            std::cout << i << " ";
        });
        std::cout << std::endl;
        std::vector<int> to_vector(15);

        std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());

        std::cout << "After copy_backward, the to_vector contains: ";
        std::for_each(to_vector.begin(), to_vector.end(), [](auto const &i) {
            std::cout << i << " ";
        });
        std::cout << std::endl;
    };

}