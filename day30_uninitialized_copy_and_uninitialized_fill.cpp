//
// Created by LongXiaJun on 2019/1/5 0005.
//

#include "day30_uninitialized_copy_and_uninitialized_fill.h"
#include <string>
#include <algorithm>
#include <memory>
#include <tuple>
#include <iostream>
#include <cstdlib>
#include <cstdalign>

namespace demo_uninitialized_copy_and_uninitialized_fill{

    namespace definition{
        // Possible definition
        template<typename InputIt, typename ForwardIt>
        ForwardIt uninitialized_copy(InputIt first, InputIt last, ForwardIt d_first)
        {
            typedef typename std::iterator_traits<ForwardIt>::value_type Value;
            ForwardIt current = d_first;
            try {
                for (; first != last; ++first, (void) ++current) {
                    ::new (static_cast<void*>(std::addressof(*current))) Value(*first);
                }
                return current;
            } catch (...) {
                for (; d_first != current; ++d_first) {
                    d_first->~Value();
                }
                throw;
            }
        }

        template<typename ForwardIt, typename T>
        void uninitialized_fill(ForwardIt first, ForwardIt last, const T& value)
        {
            typedef typename std::iterator_traits<ForwardIt>::value_type Value;
            ForwardIt current = first;
            try {
                for (; current != last; ++current) {
                    ::new (static_cast<void*>(std::addressof(*current))) Value(value);
                }
            }  catch (...) {
                for (; first != current; ++first) {
                    first->~Value();
                }
                throw;
            }
        }
    }


    void stl_uninitialized_copy_and_uninitialized_fill(){


        std::cout << "STL uninitialized_fill usage demo:\n";
        std::string* p;
        std::size_t sz1;
        std::tie(p, sz1) = std::get_temporary_buffer<std::string>(4);

        std::uninitialized_fill(p, p+sz1, "Example");

        for (std::string* i = p; i != p+sz1; ++i) {
            std::cout << *i << '\n';
            i->~basic_string<char>();
        }
        std::return_temporary_buffer(p);

        std::cout << "STL uninitialized_copy usage demo:\n";
        const char *v[] = {"This", "is", "an", "example"};

        auto sz = std::size(v);

        if(void *pbuf = _aligned_malloc(alignof(std::string), sizeof(std::string) * sz))
        {
            try
            {
                auto first = static_cast<std::string*>(pbuf);
                auto last = std::uninitialized_copy(std::begin(v), std::end(v), first);

                for (auto it = first; it != last; ++it)
                    std::cout << *it << '_';

                std::destroy(first, last);
            }
            catch(...) {}
            std::free(pbuf);
        }



    }
}
