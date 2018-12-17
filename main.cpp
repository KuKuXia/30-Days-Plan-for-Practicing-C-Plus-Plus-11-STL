#include <iostream>
#include <vector>
#include <algorithm>
#include "day2_for_each.h"
#include "day2_for_each_n.h"
#include "day2_qsort.h"
#include "day2_bsearch.h"
#include "day3_count_and_count_if.h"
#include "day3_mismatch.h"
#include "day4_find_and_find_if_and_find_if_not.h"
#include "day4_find_end.h"
#include "day5_find_first_of.h"
#include "day5_adjacent_find.h"
#include "day6_search.h"
#include "day6_search_n.h"
#include "day7_copy_and_copy_if.h"
#include "day7_copy_n_and_copy_backward.h"
#include "day8_move_and_move_backward.h"
#include "day8_fill_and_fill_n.h"
#include "day9_transform.h"
#include "day9_generate_and_generate_n.h"
#include "day10_move_and_move_if.h"
#include "day10_remove_copy_and_remove_copy_if.h"
#include "day11_replace_and_replace_if.h"

using namespace std;


template<typename T>
void printData(const T &data);


int main() {
    demo_for_each::stl_for_each();
    demo_for_each_n::stl_for_each_n();
    demo_qsort::stl_qsort();
    demo_bsearch::stl_bsearch();
    demo_count_and_count_if::stl_count_and_count_if();
    demo_mismatch::stl_mismatch();
    demo_find_and_find_if_and_find_if_not::stl_find_and_find_if_and_find_if_not();
    demo_find_end::stl_find_end();
    demo_find_first_of::stl_find_first_of();
    demo_adjacent_find::std_adjacent_find();
    demo_search::stl_search();
    demo_search_n::stl_search_n();
    demo_copy_and_copy_if::stl_copy_and_copy_if();
    demo_copy_n_and_copy_backward::stl_copy_n_and_copy_backward();
    demo_move_and_move_backward::stl_move_and_move_backward();
    demo_fill_and_fill_n::stl_fill_and_fill_n();
    demo_transform::stl_transform();
    demo_generate_and_generate_n::stl_generate_and_generate_n();
    demo_move_and_move_if::stl_move_and_move_if();
    demo_remove_copy_and_remove_copy_if::stl_remove_copy_and_remove_copy_if();
    demo_replace_and_replace_if::stl_replace_and_replace_if();







    return 0;
}


template<typename T>
void printData(const T &data) {
    for_each(data.begin(), data.end(),[](auto const &a){ cout << a << " ";});
    cout << endl;


}

