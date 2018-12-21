//
// Created by LongXiaJun on 2018/12/21 0021.
//

#include "day15_shuffle_and_sample.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>

namespace demo_shuffle_and_sample {
    namespace definition {
        // Possible Definition
        template<typename RandomIt>
        void random_shuffle(RandomIt first, RandomIt last) {
            typename std::iterator_traits<RandomIt>::difference_type i, n;
            n = last - first;
            for (i = n - 1; i > 0; --i) {
                using std::swap;
                swap(first[i], first[std::rand() % (i + 1)]);
                // rand() % (i+1) 实际上不准确，因为生成的数对于多数 i 值不均匀分布。
                // 正确实现将实际上需要重新实现 C++11 std::uniform_distributtion ，
                // 这超出了此示例的范畴。
            }
        }

        template<typename RandomIt, typename RandomFunc>
        void random_shuffle(RandomIt first, RandomIt last, RandomFunc &&r) {
            typename std::iterator_traits<RandomIt>::difference_type i, n;
            n = last - first;
            for (i = n - 1; i > 0; --i) {
                using std::swap;
                swap(first[i], first[r(i + 1)]);
            }
        }

        template<typename RandomIt, typename URBG>
        void shuffle(RandomIt first, RandomIt last, URBG &&g) {
            typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
            typedef std::uniform_int_distribution<diff_t> distr_t;
            typedef typename distr_t::param_type param_t;

            distr_t D;
            diff_t n = last - first;
            for (diff_t i = n - 1; i > 0; --i) {
                using std::swap;
                swap(first[i], first[D(g, param_t(0, i))]);
            }
        }
    }

    void stl_shuffle_and_sample() {
        std::cout << "STL shuffle usage demo: \n";
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::cout << "The source is: \n";
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(v.begin(), v.end(), g);
        std::cout << "The shuffled source is: \n";
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";


        std::string in = "abcdefgh", out;
        std::sample(in.begin(), in.end(), std::back_inserter(out),
                    5, std::mt19937{std::random_device{}()});
        std::cout << "STL sample usage demo:\nfive random letters out of " << in << " : " << out << '\n';
    }
}