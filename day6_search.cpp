//
// Created by LongXiaJun on 2018/12/12 0012.
//

#include "day6_search.h"
#include <iostream>
#include <vector>
#include <algorithm>


namespace demo_search {
    // Possible definition
    namespace definition {
        template<typename ForwardIt1, typename ForwardIt2>
        ForwardIt1 search(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last) {
            for (;; ++first) {
                ForwardIt1 it = first;
                for (ForwardIt2 s_it = s_first;; ++it, ++first) {
                    if (s_it = s_last) {
                        return first;
                    }
                    if (it == last) {
                        return last;
                    }
                    if (!(*it == *s_it)) {
                        break;
                    }
                }
            }
        }

        template<typename ForwardIt1, typename ForwardIt2, typename BinaryPredicate>
        ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
                          ForwardIt2 s_first, ForwardIt2 s_last,
                          BinaryPredicate p) {
            for (;; ++first) {
                ForwardIt1 it = first;
                for (ForwardIt2 s_it = s_first;; ++it, ++s_it) {
                    if (s_it == s_last) {
                        return first;
                    }
                    if (it == last) {
                        return last;
                    }
                    if (!p(*it, *s_it)) {
                        break;
                    }
                }
            }
        }
    }

    template<typename Container>
    bool in_quote(const Container &cont, const std::string &s) {
        return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
    }

    void stl_search() {
        std::cout << "STL search usage demo: ";
        std::string str = "why waste time learning, when ignorance is instantaneous?";
        std::cout << "The original string is: " << str << std::endl;
        // str.find() 也能使用
        std::cout << "The substring learning is in the original string: " << std::boolalpha << in_quote(str, "learning")
                  << '\n' <<
                  "The substring lemming is in the original string: " << in_quote(str, "lemming") << '\n';

//        std::vector<char> vec(str.begin(), str.end());
//        std::cout << "The substring learning is in the original string: " << std::boolalpha << in_quote(vec, "learning")
//                  << '\n' <<
//                  "The substring lemming is in the original string: " << in_quote(vec, "lemming") << '\n';
    }


}