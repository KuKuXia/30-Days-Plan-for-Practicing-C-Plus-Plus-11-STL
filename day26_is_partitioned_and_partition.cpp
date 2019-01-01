//
// Created by LongXiaJun on 2019/1/1 0001.
//

#include "day26_is_partitioned_and_partition.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <forward_list>

namespace demo_is_partitioned_and_partition {
    namespace definition {
        // Possible definition

        template<typename InputIt, typename UnaryPredicate>
        bool is_partitioned(InputIt first, InputIt last, UnaryPredicate p) {
            for (; first != last; ++first)
                if (!p(*first))
                    break;
            for (; first != last; ++first)
                if (p(*first))
                    return false;
            return true;
        }


        template<typename ForwardIt, typename UnaryPredicate>
        ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
            first = std::find_if_not(first, last, p);
            if (first == last) return first;

            for (ForwardIt i = std::next(first); i != last; ++i) {
                if (p(*i)) {
                    std::iter_swap(i, first);
                    ++first;
                }
            }
            return first;
        }
    }

    template<typename ForwardIt>
    void quicksort(ForwardIt first, ForwardIt last) {
        if (first == last) return;
        auto pivot = *std::next(first, std::distance(first, last) / 2);
        ForwardIt middle1 = std::partition(first, last,
                                           [pivot](const auto &em) { return em < pivot; });
        ForwardIt middle2 = std::partition(middle1, last,
                                           [pivot](const auto &em) { return !(pivot < em); });
        quicksort(first, middle1);
        quicksort(middle2, last);
    }

    void stl_is_partitioned_and_partition() {
        std::cout << "STL is_partitioned demo:\n";

        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "The source is:\n";
        std::for_each(v.begin(), v.end(), [](auto const &a) { std::cout << a << " "; });
        auto is_even = [](int i) { return i % 2 == 0; };
        std::cout.setf(std::ios_base::boolalpha);
        std::cout << "The source is partitioned in even: " << std::is_partitioned(v.begin(), v.end(), is_even) << '\n';

        std::partition(v.begin(), v.end(), is_even);
        std::cout << "After partition, the source is:\n";
        std::for_each(v.begin(), v.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "The source is partitioned in even: " << std::is_partitioned(v.begin(), v.end(), is_even) << '\n';

        std::cout << "STL partition usage demo:\n";
        std::vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "Original vector:\n    ";
        for (int elem : v1)
            std::cout << elem << ' ';

        auto it = std::partition(v1.begin(), v1.end(), [](int i) { return i % 2 == 0; });

        std::cout << "\nPartitioned vector:\n    ";
        std::copy(std::begin(v1), it, std::ostream_iterator<int>(std::cout, " "));
        std::cout << " * ";
        std::copy(it, std::end(v1), std::ostream_iterator<int>(std::cout, " "));

        std::forward_list<int> fl = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
        std::cout << "\nUnsorted list:\n    ";
        for (int n : fl)
            std::cout << n << ' ';
        std::cout << '\n';

        quicksort(std::begin(fl), std::end(fl));
        std::cout << "Sorted using quicksort:\n    ";
        for (int fi : fl) std::cout << fi << ' ';
        std::cout << '\n';

    }

}