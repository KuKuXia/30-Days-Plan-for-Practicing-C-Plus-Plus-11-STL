//
// Created by LongXiaJun on 2019/1/2 0002.
//

#include "day27_set_difference_and_set_intersection.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace demo_set_difference_and_set_intersection {
    namespace definition {
        template<typename InputIt1, typename InputIt2, typename OutputIt>
        OutputIt set_difference(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2,
                                OutputIt d_first) {
            while (first1 != last1) {
                if (first2 == last2) return std::copy(first1, last1, d_first);

                if (*first1 < *first2) {
                    *d_first++ = *first1++;
                } else {
                    if (!(*first2 < *first1)) {
                        ++first1;
                    }
                    ++first2;
                }
            }
            return d_first;
        }

        template<typename InputIt1, typename InputIt2,
                typename OutputIt, typename Compare>
        OutputIt set_difference(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2,
                                OutputIt d_first, Compare comp) {
            while (first1 != last1 && first2 != last2) {
                if (comp(*first1, *first2)) {
                    ++first1;
                } else {
                    if (!comp(*first2, *first1)) {
                        *d_first++ = *first1++;
                    }
                    ++first2;
                }
            }
            return d_first;
        }

        template<typename InputIt1, typename InputIt2, typename OutputIt>
        OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
                                  InputIt2 first2, InputIt2 last2,
                                  OutputIt d_first) {
            while (first1 != last1 && first2 != last2) {
                if (*first1 < *first2) {
                    ++first1;
                } else {
                    if (!(*first2 < *first1)) {
                        *d_first++ = *first1++;
                    }
                    ++first2;
                }
            }
            return d_first;
        }

        template<typename InputIt1, typename InputIt2,
                typename OutputIt, typename Compare>
        OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
                                  InputIt2 first2, InputIt2 last2,
                                  OutputIt d_first, Compare comp) {
            while (first1 != last1 && first2 != last2) {
                if (comp(*first1, *first2)) {
                    ++first1;
                } else {
                    if (!comp(*first2, *first1)) {
                        *d_first++ = *first1++;
                    }
                    ++first2;
                }
            }
            return d_first;
        }


    }

    void stl_set_difference_and_set_intersection() {
        std::cout << "STL set_difference and set_intersection usage demo:\n";
        std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
        std::vector<int> v2{5, 7, 9, 10};
        std::cout << "The v1 is: ";
        std::for_each(v1.begin(), v1.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\nThe v2 is: ";
        std::for_each(v2.begin(), v2.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\n";
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        std::vector<int> v_difference;

        std::set_difference(v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_difference));
        std::cout << "The difference between v1 and v2 is: ";
        for (int n : v_difference)
            std::cout << n << ' ';
        std::cout << '\n';


        std::vector<int> v_intersection;

        std::set_intersection(v1.begin(), v1.end(),
                              v2.begin(), v2.end(),
                              std::back_inserter(v_intersection));
        std::cout << "The intersection between v1 and v2 is: ";

        for (int n : v_intersection)
            std::cout << n << ' ';
        std::cout << '\n';
    }
}