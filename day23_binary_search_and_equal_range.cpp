//
// Created by LongXiaJun on 2018/12/29 0029.
//

#include "day23_binary_search_and_equal_range.h"
#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_binary_search_and_equal_range {
    namespace definition {
        // Possible definition
        template<typename ForwardIt, typename T>
        bool binary_search(ForwardIt first, ForwardIt last, const T &value) {
            first = std::lower_bound(first, last, value);
            return (!(first == last) && !(value < *first));
        }

        template<typename ForwardIt, typename T, typename Compare>
        bool binary_search(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
            first = std::lower_bound(first, last, value, comp);
            return (!(first == last) && !(comp(value, *first)));
        }

        template<typename ForwardIt, typename T>
        std::pair<ForwardIt, ForwardIt>
        equal_range(ForwardIt first, ForwardIt last,
                    const T &value) {
            return std::make_pair(std::lower_bound(first, last, value),
                                  std::upper_bound(first, last, value));
        }

        template<typename ForwardIt, typename T, typename Compare>
        std::pair<ForwardIt, ForwardIt>
        equal_range(ForwardIt first, ForwardIt last,
                    const T &value, Compare comp) {
            return

                    std::make_pair(std::lower_bound(first, last, value, comp),
                                   std::upper_bound(first, last, value, comp)

                    );
        }
    }

    struct S {
        int number;
        char name;

        // 注意：此比较运算符忽略 name
        bool operator<(const S &s) const { return number < s.number; }
    };


    void stl_binary_search_and_equal_range() {
        std::cout << "STL binary_search usage demo:\n";

        std::vector<int> haystack{1, 3, 4, 5, 9};
        std::vector<int> needles{1, 2, 3};

        for (auto needle : needles) {
            std::cout << "Searching for " << needle << '\n';
            if (std::binary_search(haystack.begin(), haystack.end(), needle)) {
                std::cout << "Found " << needle << '\n';
            } else {
                std::cout << "no dice!\n";
            }
        }

        std::cout << "STL equal_range usage demo: \n";

        // 注意：非有序，仅相对于定义于下的 S 划分
        std::vector<S> vec = {{1, 'A'},
                              {2, 'B'},
                              {2, 'C'},
                              {2, 'D'},
                              {4, 'G'},
                              {3, 'F'}};

        S value = {2, '?'};

        auto p = std::equal_range(vec.begin(), vec.end(), value);

        for (auto i = p.first; i != p.second; ++i)
            std::cout << i->name << ' ';


        // 异相比较:
        struct Comp {
            bool operator()(const S &s, int i) const { return s.number < i; }

            bool operator()(int i, const S &s) const { return i < s.number; }
        };

        auto p2 = std::equal_range(vec.begin(), vec.end(), 2, Comp{});

        for (auto i = p2.first; i != p2.second; ++i)
            std::cout << i->name << ' ';
    }
}