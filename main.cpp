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
#include "day11_replace_copy_and_replace_copy_if.h"
#include "day12_swap_and_swap_ranges_and_iter_swap.h"
#include "day13_reverse_and_reverse_copy.h"
#include "day14_rotate_and_rotate_copy.h"
#include "day15_shuffle_and_sample.h"
#include "day16_unqiue_and_unique_copy.h"
#include "day17_is_sorted_and_is_sorted_until.h"
#include "day18_sort_and_partial_sort_and_partial_sort_copy.h"
#include "day19_stable_sort_and_nth_element.h"
#include "day20_max_and_max_element.h"
#include "day20_min_and_min_element.h"
#include "day21_minmax_and_minmax_element.h"
#include "day22_is_permutation_and_prev_permutation_and_next_permutation.h"
#include "day22_lower_bound_and_upper_bound.h"
#include "day23_binary_search_and_equal_range.h"
#include "day23_equal_and_lexicographical_compare.h"
#include "day24_iota_and_accumulate.h"
#include "day24_inner_product_and_adjacent_difference.h"
#include "day25_partial_sum_and_includes.h"
#include "day26_is_partitioned_and_partition.h"
#include "day26_partition_copy_and_stable_partition_and_partition_point.h"
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
    demo_replace_copy_and_replace_copy_if::stl_replace_copy_and_replace_copy_if();
    demo_swap_and_swap_ranges_and_iter_swap::stl_swap_and_swap_ranges_and_iter_swap();
    demo_reverse_and_reverse_copy::stl_reverse_and_reverse_copy();
    demo_rotate_and_rotate_copy::stl_rotate_and_rotate_copy();
    demo_shuffle_and_sample::stl_shuffle_and_sample();
    demo_unique_and_unique_copy::stl_unique_and_unique_copy();
    demo_is_sorted_and_is_sorted_until::stl_is_sorted_and_is_sorted_until();
    demo_sort_and_partial_sort_and_partial_sort_copy::stl_sort_and_partial_sort_and_partial_sort_copy();
    demo_stable_and_nth_element::stl_stable_and_nth_element();
    demo_max_and_max_lelment::stl_max_and_max_element();
    demo_min_and_min_element::stl_min_and_min_element();
    demo_minmax_and_minmax_element::stl_minmax_and_minmax_element();
    demo_is_permutation_and_prev_permutation_and_next_permutation::stl_is_permutation_and_prev_permutation_and_next_permutation();
    demo_lower_bound_and_upper_bound::stl_lower_bound_and_upper_bound();
    demo_binary_search_and_equal_range::stl_binary_search_and_equal_range();
    demo_equal_and_lexicographical_compare::stl_equal_and_lexicographical_compare();
    demo_iota_and_accumulate::stl_iota_and_accumulate();
    demo_inner_product_and_adjacent_difference::stl_inner_product_and_adjacent_difference();
    demo_partial_sum_and_includes::stl_partial_sum_and_includes();
    demo_is_partitioned_and_partition::stl_is_partitioned_and_partition();
    demo_partition_copy_and_stable_partition_and_partition_point::partition_copy_and_stable_partition_and_partition_point();
    return 0;


}


template<typename T>
void printData(const T &data) {
    for_each(data.begin(), data.end(), [](auto const &a) { cout << a << " "; });
    cout << endl;
}

