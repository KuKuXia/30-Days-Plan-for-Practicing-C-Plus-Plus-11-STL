//
// Created by LongXiaJun on 2018/12/25 0025.
//

#include "day19_stable_sort_and_nth_element.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace demo_stable_and_nth_element {
    struct Employee {
        int age;
        std::string name;
    };

    bool operator<(const Employee &lhs, const Employee &rhs) {
        return lhs.age < rhs.age;
    }

    void stl_stable_and_nth_element() {
        std::vector<Employee> v = {{108, "Zaphod"},
                                   {32,  "Arthur"},
                                   {108, "Ford"},};
        std::cout << "STL stable usage demo: \n";
        std::cout << "The source vector is:\n";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a.name << " " << a.age << "\n";
        });
        std::stable_sort(v.begin(), v.end());
        std::cout << "After stable_sort, the source is: \n";
        std::for_each(v.begin(), v.end(), [](auto const &a) {
            std::cout << a.name << " " << a.age << "\n";
        });

        std::cout << "STL nth_element usage demo: \n";
        std::vector<int> v1{5, 6, 4, 3, 2, 6, 7, 9, 3};
        std::cout << "The source is:\n";
        std::for_each(v1.begin(), v1.end(), [](auto const &a) {
            std::cout << a << " ";
        });
        std::cout << '\n';

        std::nth_element(v1.begin(), v1.begin() + v1.size() / 2, v1.end());
        std::cout << "The median is " << v1[v1.size() / 2] << '\n';

        std::nth_element(v1.begin(), v1.begin() + 1, v1.end(), std::greater<int>());
        std::cout << "The second largest element is " << v1[1] << '\n';

    }

}