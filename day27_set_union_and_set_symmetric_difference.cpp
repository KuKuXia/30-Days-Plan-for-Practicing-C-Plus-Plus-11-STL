//
// Created by LongXiaJun on 2019/1/2 0002.
//

#include "day27_set_union_and_set_symmetric_difference.h"
#include <vector>
#include <iostream>
#include <algorithm>


namespace demo_set_union_and_set_symmetric_difference {
    namespace definition {
        // Possible
        template<typename InputIt1, typename InputIt2, typename OutputIt>
        OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
                                          InputIt2 first2, InputIt2 last2,
                                          OutputIt d_first) {
            while (first1 != last1) {
                if (first2 == last2) return std::copy(first1, last1, d_first);

                if (*first1 < *first2) {
                    *d_first++ = *first1++;
                } else {
                    if (*first2 < *first1) {
                        *d_first++ = *first2;
                    } else {
                        ++first1;
                    }
                    ++first2;
                }
            }
            return std::copy(first2, last2, d_first);
        }

        template<typename InputIt1, typename InputIt2,
                typename OutputIt, typename Compare>
        OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
                                          InputIt2 first2, InputIt2 last2,
                                          OutputIt d_first, Compare comp) {
            while (first1 != last1) {
                if (first2 == last2) return std::copy(first1, last1, d_first);

                if (comp(*first1, *first2)) {
                    *d_first++ = *first1++;
                } else {
                    if (comp(*first2, *first1)) {
                        *d_first++ = *first2;
                    } else {
                        ++first1;
                    }
                    ++first2;
                }
            }
            return std::copy(first2, last2, d_first);
        }

        template<typename InputIt1, typename InputIt2, typename OutputIt>
        OutputIt set_union(InputIt1 first1, InputIt1 last1,
                           InputIt2 first2, InputIt2 last2,
                           OutputIt d_first) {
            for (; first1 != last1; ++d_first) {
                if (first2 == last2)
                    return std::copy(first1, last1, d_first);
                if (*first2 < *first1) {
                    *d_first = *first2++;
                } else {
                    *d_first = *first1;
                    if (!(*first1 < *first2))
                        ++first2;
                    ++first1;
                }
            }
            return std::copy(first2, last2, d_first);
        }

        template<typename InputIt1, typename InputIt2,
                typename OutputIt, typename Compare>
        OutputIt set_union(InputIt1 first1, InputIt1 last1,
                           InputIt2 first2, InputIt2 last2,
                           OutputIt d_first, Compare comp) {
            for (; first1 != last1; ++d_first) {
                if (first2 == last2)
                    return std::copy(first1, last1, d_first);
                if (comp(*first2, *first1)) {
                    *d_first = *first2++;
                } else {
                    *d_first = *first1;
                    if (!comp(*first1, *first2))
                        ++first2;
                    ++first1;
                }
            }
            return std::copy(first2, last2, d_first);
        }

    }

    void stl_set_union_and_set_symmetric_difference() {
        std::cout << "STL set_symmetric usage demo:\n";
        std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
        std::vector<int> v2{5, 7, 9, 10};
        std::cout << "The v1 is: ";
        std::for_each(v1.begin(), v1.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << "\nThe v2 is: ";
        std::for_each(v2.begin(), v2.end(), [](auto const &a) { std::cout << a << " "; });
        std::cout << '\n';

        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        std::vector<int> v_symDifference;

        std::set_symmetric_difference(
                v1.begin(), v1.end(),
                v2.begin(), v2.end(),
                std::back_inserter(v_symDifference));
        std::cout << "The symmetric difference between v1 and v2 is: ";
        for (int n : v_symDifference)
            std::cout << n << ' ';


        std::cout << '\n';
        std::cout << "STL set_union usage demo:\n";

        std::vector<int> dest1;

        std::set_union(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),
                       std::back_inserter(dest1));
        std::cout << "The union of v1 and v2 is: ";

        for (const auto &i : dest1) {
            std::cout << i << ' ';
        }
        std::cout << '\n';


    }
}