//
// Created by LongXiaJun on 2018/12/14 0014.
//

#include "day8_move_and_move_backward.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>
#include <thread>
#include <chrono>


namespace demo_move_and_move_backward {
    namespace definition {
        // Possible definition
        template<typename InputIt, typename OutputIt>
        OutputIt move(InputIt first, InputIt last, OutputIt d_first) {
            while (first != last) {
                *d_first++ = std::move(*first++);
            }
            return d_first;
        }

        template<typename BidirIt1, typename BidirIt2>
        BidirIt2 move_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last) {
            while (last != first) {
                *(--d_last) = std::move(*(--last));
            }
            return d_last;
        }
    }

    void f(int n) {
        std::this_thread::sleep_for(std::chrono::seconds(n));
        std::cout << "thread" << n << " ended \n";

    }

    void stl_move_and_move_backward() {
        std::cout << "STL move and move_backward usage demo: \n";
        std::vector<std::thread> v;
        v.emplace_back(f, 1);
        v.emplace_back(f, 2);
        std::list<std::thread> l; // copy 无法编译，因为std::thread不可复制
        std::move(v.begin(), v.end(), std::back_inserter(l));
        std::for_each(l.begin(), l.end(), [](auto &a) { a.join(); });

        std::cout << "STL move_backward usage demo: \n";
        std::vector<std::string> src{"foo", "bar", "baz"};
        std::vector<std::string> dest(src.size());

        std::cout << "src: ";
        for (const auto &s : src) {
            std::cout << s << ' ';
        }
        std::cout << "\ndest: ";
        for (const auto &s : dest) {
            std::cout << s << ' ';
        }
        std::cout << '\n';

        std::move_backward(src.begin(), src.end(), dest.end());

        std::cout << "src: ";
        for (const auto &s : src) {
            std::cout << s << ' ';
        }
        std::cout << "\ndest: ";
        for (const auto &s : dest) {
            std::cout << s << ' ';
        }
        std::cout << '\n';
    }

}