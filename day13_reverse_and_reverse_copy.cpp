//
// Created by LongXiaJun on 2018/12/19 0019.
//

#include "day13_reverse_and_reverse_copy.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace demo_reverse_and_reverse_copy {
    namespace Definition {
        //Possible definition

        template<typename BidirIt>
        void reverse(BidirIt first, BidirIt last)
        {
            while ((first != last) && (first != --last)) {
                std::iter_swap(first++, last);
            }
        }

        template<typename BidirIt, typename OutputIt>
        OutputIt reverse_copy(BidirIt first, BidirIt last, OutputIt d_first)
        {
            while (first != last) {
                *(d_first++) = *(--last);
            }
            return d_first;
        }
    }

    void stl_reverse_and_reverse_copy(){
        std::cout << "STL reverse and reverse_copy usage demo: " << std::endl;
        std::vector<int> v{1,2,3,4,5,6};
        std::cout << "Source vector is: ";
        std::for_each(v.begin(),v.end(),[](auto const&a){ std::cout << a<<" ";});
        std::reverse(std::begin(v), std::end(v));
        std::cout << std::endl << "After reverse, Source vector is: ";
        std::for_each(v.begin(),v.end(),[](auto const&a){ std::cout << a<<" ";});


        std::vector<int> v1(v.size());
        std::cout << "\nSource1 vector is: ";
        std::for_each(v1.begin(),v1.end(),[](auto const&a){ std::cout << a<<" ";});
        std::reverse_copy(std::begin(v), std::end(v),v1.begin());
        std::cout << std::endl << "After reverse, Source vector is: ";
        std::for_each(v1.begin(),v1.end(),[](auto const&a){ std::cout << a<<" ";});


    }
}

