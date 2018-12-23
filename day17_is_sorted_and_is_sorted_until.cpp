//
// Created by LongXiaJun on 2018/12/23 0023.
//

#include "day17_is_sorted_and_is_sorted_until.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <random>


namespace demo_is_sorted_and_is_sorted_until {
    namespace definition {
        template<typename ForwardIt>
        ForwardIt is_sorted_until(ForwardIt first, ForwardIt last) {
            if (first != last) {
                ForwardIt next = first;
                while (++next != last) {
                    if (*next < *first)
                        return next;
                    first = next;
                }
            }
            return last;
        }

        template<typename ForwardIt, typename Compare>
        ForwardIt is_sorted_until(ForwardIt first, ForwardIt last, Compare comp) {
            using namespace std::placeholders;
            ForwardIt it = std::adjacent_find(first, last, std::bind(comp, _2, _1));
            return it == last ? last : std::next(it);
        }

        template<typename ForwardIt>
        bool is_sorted(ForwardIt first, ForwardIt last) {
            return std::is_sorted_until(first, last) == last;
        }

        template<typename ForwardIt, typename Compare>
        bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
            return std::is_sorted_until(first, last, comp) == last;
        }
    }

    void stl_is_sorted_and_is_sorted_until() {
        std::cout << "STL is_sorted usage demo: \nThe source is: ";
        std::vector<int> source{1, 2, 3, 4, 32, 5, 6};
        std::for_each(source.begin(), source.end(), [](auto const &a) { std::cout << a << " "; });

        std::cout << ": is_sorted: " << std::boolalpha << std::is_sorted(source.begin(), source.end()) << "\n";

        std::sort(source.begin(), source.end());
        std::cout << "After sort operation, the source is_sorted: " << std::boolalpha
                  << std::is_sorted(source.begin(), source.end()) << "\n";

        std::random_device rd;
        std::mt19937 g(rd());
        const int N = 6;
        int nums[N] = {3, 1, 4, 1, 5, 9};

        const int min_sorted_size = 3;
        int sorted_size = 0;
        std::cout << "STL is_sorted_until usage demo:\n";
        do {
            std::shuffle(nums, nums + N, g);
            int *sorted_end = std::is_sorted_until(nums, nums + N);
            sorted_size = std::distance(nums, sorted_end);

            for (auto i : nums) std::cout << i << ' ';
            std::cout << " : " << sorted_size << " initial sorted elements\n";
        } while (sorted_size < min_sorted_size);


    }

}

















