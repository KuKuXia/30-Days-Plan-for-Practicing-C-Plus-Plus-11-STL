//
// Created by LongXiaJun on 2018/12/18 0018.
//

#include "day12_swap_and_swap_ranges_and_iter_swap.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <random>
#include <functional>

namespace demo_swap_and_swap_ranges_and_iter_swap{
    namespace definition {
        // Possible definition
        template<typename ForwardIt1, typename ForwardIt2>
        ForwardIt2 swap_ranges(ForwardIt1 first1,
                               ForwardIt1 last1,
                               ForwardIt2 first2)
        {
            while (first1 != last1) {
                std::iter_swap(first1++, first2++);
            }
            return first2;
        }


        template<typename ForwardIt1, typename ForwardIt2>
        void iter_swap(ForwardIt1 a, ForwardIt2 b)
        {
            using std::swap;
            swap(*a, *b);
        }

    }

    template<typename ForwardIt>
    void selection_sort(ForwardIt begin, ForwardIt end)
    {
        for (ForwardIt i = begin; i != end; ++i)
            std::iter_swap(i, std::min_element(i, end));
    }

    void stl_swap_and_swap_ranges_and_iter_swap(){
        std::cout << "STL swap and swap_ranges_and_iter_swap usage demo: \n";
        int a = 5, b = 3;

        // 前
        std::cout << "Before swap, a: " <<a <<  " b: "  << b << '\n';
        std::swap(a,b);

        // 后
        std::cout << "After swap, a: " << a << " b: " << b << '\n';

        std::vector<int> v = {1, 2, 3, 4, 5};
        std::list<int> l = {-1, -2, -3, -4, -5};

        std::cout << "Before swap_ranges, v is: ";
                                                  std::for_each(v.begin(),v.end(),[](auto const &a ){ std::cout << a << " ";});
        std::cout << std::endl << "l is: ";
        std::for_each(l.begin(),l.end(),[](auto const &a ){ std::cout << a << " ";});
        std::cout << std::endl;
        std::swap_ranges(v.begin(), v.begin()+3, l.begin());

        std::cout << "After swap 3 elements, v is: ";
        for(int n : v)
            std::cout << n << ' ';
        std::cout << '\n';
        std::cout << "After swap_ranges, l is: ";
        for(int n : l)
            std::cout << n << ' ';
        std::cout << '\n';

        std::cout << "Demo for iter_swap: \n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-10, 10);
        std::list<int> v1;
        generate_n(back_inserter(v1), 20, std::bind(dist, gen));

        std::cout << "Before sort: ";
        for(auto e : v1) std::cout << e << " ";

        selection_sort(v1.begin(), v1.end());

        std::cout << "\nAfter sort: ";
        for(auto e : v1) std::cout << e << " ";
        std::cout << '\n';
    };
}