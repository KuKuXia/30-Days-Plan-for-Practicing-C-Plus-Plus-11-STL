//
// Created by LongXiaJun on 2019/1/3 0003.
//

#include "day28_merge_and_inplace_merge.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#include <iterator>

namespace demo_merge_and_inplace_merge {
    namespace definition {
        // Possible definition
        template<typename InputIt1, typename InputIt2, typename OutputIt>
        OutputIt merge(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, InputIt2 last2,
                       OutputIt d_first) {
            for (; first1 != last1; ++d_first) {
                if (first2 == last2) {
                    return std::copy(first1, last1, d_first);
                }
                if (*first2 < *first1) {
                    *d_first = *first2;
                    ++first2;
                } else {
                    *d_first = *first1;
                    ++first1;
                }
            }
            return std::copy(first2, last2, d_first);
        }

        template<typename InputIt1, typename InputIt2,
                typename OutputIt, typename Compare>
        OutputIt merge(InputIt1 first1, InputIt1 last1,
                       InputIt2 first2, InputIt2 last2,
                       OutputIt d_first, Compare comp) {
            for (; first1 != last1; ++d_first) {
                if (first2 == last2) {
                    return std::copy(first1, last1, d_first);
                }
                if (comp(*first2, *first1)) {
                    *d_first = *first2;
                    ++first2;
                } else {
                    *d_first = *first1;
                    ++first1;
                }
            }
            return std::copy(first2, last2, d_first);
        }

    }

    template<typename Iter>
    void merge_sort(Iter first, Iter last) {
        if (last - first > 1) {
            Iter middle = first + (last - first) / 2;
            merge_sort(first, middle);
            merge_sort(middle, last);
            std::inplace_merge(first, middle, last);
        }
    }

    void stl_merge_and_inplace_merge() {
        std::cout << "STL merge usage demo:\n";
        // 以随机数填充 vector
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dis(0, 9);

        std::vector<int> v1(10), v2(10);
        std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
        std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));

        // 排序
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        // 输出 v1
        std::cout << "v1 : ";
        std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';

        // 输出 v2
        std::cout << "v2 : ";
        std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';

        // 归并
        std::vector<int> dst;
        std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));

        // 输出
        std::cout << "After merge v1 and v2: ";
        std::copy(dst.begin(), dst.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';

        std::cout << "STL inplace_merge usage demo:\n";
        std::vector<int> v{8, 2, -2, 0, 11, 11, 1, 7, 3};
        std::cout << "The source is : ";
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\nAfter merge and inplace_merge operation, the source is: ";
        merge_sort(v.begin(), v.end());
        for (auto n : v) {
            std::cout << n << ' ';
        }
        std::cout << '\n';


    }


}