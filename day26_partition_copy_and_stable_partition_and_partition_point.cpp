//
// Created by LongXiaJun on 2019/1/1 0001.
//

#include "day26_partition_copy_and_stable_partition_and_partition_point.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <iterator>

namespace demo_partition_copy_and_stable_partition_and_partition_point {
    namespace definition {
        // Possible definition

        template<class InputIt, class OutputIt1,
                class OutputIt2, class UnaryPredicate>
        std::pair<OutputIt1, OutputIt2>
        partition_copy(InputIt first, InputIt last,
                       OutputIt1 d_first_true, OutputIt2 d_first_false,
                       UnaryPredicate p) {
            while (first != last) {
                if (p(*first)) {
                    *d_first_true = *first;
                    ++d_first_true;
                } else {
                    *d_first_false = *first;
                    ++d_first_false;
                }
                ++first;
            }
            return std::pair<OutputIt1, OutputIt2>(d_first_true, d_first_false);
        }


    }

    void partition_copy_and_stable_partition_and_partition_point() {
        std::cout << "STL partition_copy usage demo:\n";
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int true_arr[5] = {0};
        int false_arr[5] = {0};
        std::cout << "The source is:\n";
        std::for_each(std::begin(arr), std::end(arr), [](auto const &a) { std::cout << a << " "; });
        std::partition_copy(std::begin(arr), std::end(arr), std::begin(true_arr), std::begin(false_arr),
                            [](int i) { return i > 5; });

        std::cout << "\nGreater than 5: ";
        for (auto x : true_arr) {
            std::cout << x << ' ';
        }
        std::cout << '\n';

        std::cout << "Less than 5: ";
        for (auto x : false_arr) {
            std::cout << x << ' ';
        }
        std::cout << '\n';

        std::cout << "STL stable_partition usage demo:\n";

        std::vector<int> v{0, 0, 3, 0, 2, 4, 5, 0, 7};
        std::cout << "The source is: ";
        std::for_each(std::begin(v), std::end(v), [](auto const &a) { std::cout << a << " "; });
        std::cout << '\n';
        std::stable_partition(v.begin(), v.end(), [](int n) { return n > 0; });
        std::cout << "After stable_partition: ";
        for (int n : v) {
            std::cout << n << ' ';
        }
        std::cout << '\n';

        std::cout << "STL partition_point usage demo:\n";
        std::array<int, 9> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "The source is:\n";
        std::for_each(std::begin(v1), std::end(v1), [](auto const &a) { std::cout << a << " "; });
        auto is_even = [](int i) { return i % 2 == 0; };
        std::partition(v1.begin(), v1.end(), is_even);

        auto p = std::partition_point(v1.begin(), v1.end(), is_even);

        std::cout << "\nBefore partition: ";
        std::copy(v1.begin(), p, std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\nAfter partition: ";
        std::copy(p, v1.end(), std::ostream_iterator<int>(std::cout, " "));
    }

}