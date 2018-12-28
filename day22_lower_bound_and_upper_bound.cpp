//
// Created by LongXiaJun on 2018/12/28 0028.
//

#include <iterator>
#include "day22_lower_bound_and_upper_bound.h"
#include "algorithm"
#include "iostream"
#include "vector"


namespace demo_lower_bound_and_upper_bound {
    namespace definition {
        // Possible definition
        template<typename ForwardIt, typename T>
        ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &value) {
            ForwardIt it;
            typename std::iterator_traits<ForwardIt>::difference_type count, step;
            count = std::distance(first, last);

            while (count > 0) {
                it = first;
                step = count / 2;
                std::advance(it, step);
                if (*it < value) {
                    first = ++it;
                    count -= step + 1;
                } else
                    count = step;
            }
            return first;
        }

        template<typename ForwardIt, typename T, typename Compare>
        ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
            ForwardIt it;
            typename std::iterator_traits<ForwardIt>::difference_type count, step;
            count = std::distance(first, last);

            while (count > 0) {
                it = first;
                step = count / 2;
                std::advance(it, step);
                if (comp(*it, value)) {
                    first = ++it;
                    count -= step + 1;
                } else
                    count = step;
            }
            return first;
        }

        template<typename ForwardIt, typename T>
        ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T &value) {
            ForwardIt it;
            typename std::iterator_traits<ForwardIt>::difference_type count, step;
            count = std::distance(first, last);

            while (count > 0) {
                it = first;
                step = count / 2;
                std::advance(it, step);
                if (!(value < *it)) {
                    first = ++it;
                    count -= step + 1;
                } else
                    count = step;
            }
            return first;
        }

        template<typename ForwardIt, typename T, typename Compare>
        ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
            ForwardIt it;
            typename std::iterator_traits<ForwardIt>::difference_type count, step;
            count = std::distance(first, last);

            while (count > 0) {
                it = first;
                step = count / 2;
                std::advance(it, step);
                if (!comp(value, *it)) {
                    first = ++it;
                    count -= step + 1;
                } else
                    count = step;
            }
            return first;
        }


    }

    template<typename ForwardIt, typename T, typename Compare=std::less<>>
    ForwardIt binary_find(ForwardIt first, ForwardIt last, const T &value, Compare comp = {}) {
        // 注意：类型 T 和 Forward 解引用后的类型都必须可隐式转换为
        // 用于 Compare 的 Type1 和 Type2 。
        // 这严格于 lower_bound 要求（见上述）

        first = std::lower_bound(first, last, value, comp);
        return first != last && !comp(value, *first) ? first : last;
    }


    void stl_lower_bound_and_upper_bound() {
        std::cout << "STL lower_bound and upper_bound usage demo: \n";
        std::vector<int> data = {1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6};

        auto lower = std::lower_bound(data.begin(), data.end(), 4);
        auto upper = std::upper_bound(data.begin(), data.end(), 4);

        std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

        std::cout << '\n';

        // 经典二分搜索，仅若存在才返回值

        data = {1, 2, 4, 6, 9, 10};

        auto it = binary_find(data.cbegin(), data.cend(), 4); // 选择 '5' 的 < 将返回 end()

        if (it != data.cend())
            std::cout << *it << " found at index " << std::distance(data.cbegin(), it);


    }
}