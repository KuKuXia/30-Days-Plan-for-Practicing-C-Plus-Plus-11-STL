//
// Created by LongXiaJun on 2018/12/30 0030.
//

#include "day24_iota_and_accumulate.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <list>
#include <string>
#include <numeric>
#include <functional>


namespace demo_iota_and_accumulate {
    namespace definition {
        // Possible definition

        template<typename ForwardIterator, typename T>
        void iota(ForwardIterator first, ForwardIterator last, T value) {
            while (first != last) {
                *first++ = value;
                ++value;
            }
        }

        template<typename InputIt, typename T>
        T accumulate(InputIt first, InputIt last, T init) {
            for (; first != last; ++first) {
                init = std::move(init) + *first; // C++20 起有 std::move
            }
            return init;
        }

        template<typename InputIt, typename T, typename BinaryOperation>
        T accumulate(InputIt first, InputIt last, T init,
                     BinaryOperation op) {
            for (; first != last; ++first) {
                init = op(std::move(init), *first); // C++20 起有 std::move
            }
            return init;
        }


    }

    void stl_iota_and_accumulate() {

        std::cout << "STL iota usage demo\n";
        std::list<int> l(10);
        std::iota(l.begin(), l.end(), -4);

        std::vector<std::list<int>::iterator> v(l.size());
        std::iota(v.begin(), v.end(), l.begin());

        std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

        std::cout << "Contents of the list: ";
        for (auto n: l) std::cout << n << ' ';
        std::cout << '\n';

        std::cout << "Contents of the list, shuffled: ";
        for (auto i: v) std::cout << *i << ' ';
        std::cout << '\n';

        std::cout << "STL accumulate usage demo:\n";
        std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int sum = std::accumulate(v1.begin(), v1.end(), 0);

        int product = std::accumulate(v1.begin(), v1.end(), 1, std::multiplies<int>());

        auto dash_fold = [](std::string a, auto b) {
            return std::move(a) + '-' + std::to_string(b);
        };

        std::string s = std::accumulate(std::next(v1.begin()), v1.end(),
                                        std::to_string(v1[0]), // 用首元素开始
                                        dash_fold);

        // 使用逆向迭代器右折叠
        std::string rs = std::accumulate(std::next(v1.rbegin()), v1.rend(),
                                         std::to_string(v1.back()), // 用首元素开始
                                         dash_fold);

        std::cout << "sum: " << sum << '\n'
                  << "product: " << product << '\n'
                  << "dash-separated string: " << s << '\n'
                  << "dash-separated string (right-folded): " << rs << '\n';

    }


}