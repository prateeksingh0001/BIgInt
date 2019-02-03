#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
#include <utility>

template < typename RandomAccessIterator, typename Compare >
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
   
    size_t n = last - first ;

    if (n<=1)
        return ;

    size_t m = n/2 ;

    mergesort(first, first+m, comp);
    mergesort(first+m, last, comp);

    std::vector< std::iterator_traits<RandomAccessIterator>::value_type > v(last-first);
    RandomAccessIterator itResult = v.begin();

    RandomAccessIterator itLower = first; 
    RandomAccessIterator itUpper = first + m;

    while(itLower != first+m && itUpper != last)
        *(itResult++) = comp(*itLower, *itUpper) ? *(itLower++):*(itUpper++);


        std::move(itLower, first+m, itResult) ;
        std::move(itUpper, first+m, itResult) ;

    std::move(v.begin(), v.end(), first); 
}

template < typename RandomAccessIterator >
void mergesort(RandomAccessIterator first, RandomAccessIterator last){
    mergesort(first, last, []( std::iterator_traits<RandomAccessIterator>::value_type const& a, std::iterator_triats<RandomAccessIterator>::value_type const& b){ return a < b; });
}

#endif
