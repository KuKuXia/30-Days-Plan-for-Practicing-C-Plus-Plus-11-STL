//
// Created by LongXiaJun on 2018/12/15 0015.
//

#include "day9_generate_and_generate_n.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>
#include <functional>


namespace demo_generate_and_generate_n {
    namespace definition {
        // Possible definition
        template<typename ForwardIt, typename Generator>
        void generate(ForwardIt first, ForwardIt last, Generator g) {
            while (first != last) {
                *first++ = g();
            }
        }

        template<typename OutputIt, typename Size, typename Generator>
        OutputIt generate_n(OutputIt first, Size count, Generator g) {
            for (Size i = 0; i < count; i++) {
                *first++ = g();
            }
            return first;
        }
    }


    int f() {
        static int i = 0;
        return ++i;
    }

    void stl_generate_and_generate_n() {

        std::cout << "STL generate and generate_n usage demo: \n";
        std::vector<int> v(6);
        std::generate(v.begin(), v.end(), f);

        std::cout << "After generate, the source is: \n";
        std::for_each(v.begin(), v.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;

        // 以来自 lambda 函数的默认值 0,1,2,3,4 初始化
        // 等价于 std::iota(v.begin(), v.end(), 0);
        int n = 10;
        std::generate(v.begin(), v.end(), [n]() mutable { return n++; });  //允许 body 修改以复制捕获的参数，及调用其非 const 成员函数
        std::cout << "n is: " << n << std::endl;
        std::for_each(v.begin(), v.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << std::endl;

        std::cout << "Using mt19937 to generate 5 random number: \n";
        std::mt19937 rng; // 默认构造，以固定的种子播种
        std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                        5, std::ref(rng));
        std::cout << '\n';
    };

}