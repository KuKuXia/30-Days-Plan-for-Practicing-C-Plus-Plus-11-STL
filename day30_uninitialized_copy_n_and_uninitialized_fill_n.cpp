//
// Created by LongXiaJun on 2019/1/5 0005.
//

#include "day30_uninitialized_copy_n_and_uninitialized_fill_n.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

namespace demo_uninitialized_copy_n_and_uninitialized_fill_n {
    namespace definition{
        // Possibel definition
        template<typename InputIt, typename Size, typename ForwardIt>
        ForwardIt uninitialized_copy_n(InputIt first, Size count, ForwardIt d_first)
        {
            typedef typename std::iterator_traits<ForwardIt>::value_type Value;
            ForwardIt current = d_first;
            try {
                for (; count > 0; ++first, (void) ++current, --count) {
                    ::new (static_cast<void*>(std::addressof(*current))) Value(*first);
                }
            } catch (...) {
                for (; d_first != current; ++d_first) {
                    d_first->~Value();
                }
                throw;
            }
            return current;
        }

        template< typename ForwardIt, typename Size, typename T >
        ForwardIt uninitialized_fill_n(ForwardIt first, Size count, const T& value)
        {
            typedef typename std::iterator_traits<ForwardIt>::value_type Value;
            ForwardIt current = first;
            try {
                for (; count > 0; ++current, (void) --count) {
                    ::new (static_cast<void*>(std::addressof(*current))) Value(value);
                }
                return current;
            } catch (...) {
                for (; first != current; ++first) {
                    first->~Value();
                }
                throw;
            }
        }
        
    }

    void stl_uninitialized_copy_n_and_uninitialized_fill_n (){
        std::cout << "STL uninitialized_copy_n usage demo:\n";
        std::vector<std::string> v = {"This", "is", "an", "example"};

        std::string* p;
        std::size_t sz;
        std::tie(p, sz)  = std::get_temporary_buffer<std::string>(v.size());
        sz = std::min(sz, v.size());

        std::uninitialized_copy_n(v.begin(), sz, p);

        for (std::string* i = p; i != p+sz; ++i) {
            std::cout << *i << ' ';
            i->~basic_string<char>();
        }
        std::return_temporary_buffer(p);

        std::cout << "STL uninitialized_fill_n usage demo:\n";
        std::tie(p, sz) = std::get_temporary_buffer<std::string>(4);
        std::uninitialized_fill_n(p, sz, "Example");

        for (std::string* i = p; i != p+sz; ++i) {
            std::cout << *i << '\n';
            i->~basic_string<char>();
        }
        std::return_temporary_buffer(p);
    }
}