//
// Created by LongXiaJun on 2018/12/16 0016.
//

#include "day10_move_and_move_if.h"
#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_move_and_move_if {
    namespace definition {
        // Possible definition

        template<typename ForwardIt, typename T>
        ForwardIt remove(ForwardIt first, ForwardIt last, const T &value) {
            first = std::find(first, last, value);
            if (first != last) {
                for (ForwardIt i = first; ++i != last;) {
                    if (!(*i == value)) {
                        *first++ = std::move(*i);
                    }
                }
            }

        }


        template<typename ForwardIt, typename UnaryPredicate>
        ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
            first = std::find_if(first, last, p);
            if (first != last)
                for (ForwardIt i = first; ++i != last;)
                    if (!p(*i))
                        *first++ = std::move(*i);
            return first;
        }
    }


    void stl_move_and_move_if() {
        std::cout << "STL move and move_if usage demo:\n ";
        std::string str1 = "Text with some   spaces";
        std::cout << "Source string is: " << str1 << std::endl;
        str1.erase(std::remove(str1.begin(), str1.end(), ' '),
                   str1.end());
        std::cout << "After remove and erase the space. the str1 is: " << str1 << '\n';

        std::string str2 = "Text\n with\tsome \t  whitespaces\n";
        std::cout << "Source string2 is: " << str2 << std::endl;
        str2.erase(std::remove_if(str2.begin(),
                                  str2.end(),
                                  [](unsigned char x) { return std::isspace(x); }),
                   str2.end());
        std::cout << "After remove and erase the space. the str1 is: " << str2 << '\n';
    }
}