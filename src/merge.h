#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

/*
 * The only reason for the signature of the mergesort function having a return
 * type is bcs for the sake of the assignment we have to count the number of
 * inversions in the input array
 *
 * WARNING: This function expects the data to be ordinal and to follow the basic
 * operations as they are, i.e. it won't work for strings and other
 * data-structures yet
 */

// TODO: Implement a generic merge-sort with a comparison function that can work
// it almost any ordinal data structures.

template <typename I, typename R>
R mergesort(I *first, I *last)
{

    size_t n = last - first;

    if (n <= 1)
        return 0;

    R TotalInversions = 0;
    I m = n / 2;

    R LeftSubarrayInversions = mergesort<I, R>(first, first + m);
    R RightSubarrayInversions = mergesort<I, R>(first + m, last);

    I v[n];
    I *result = v;

    I *lower = first;
    I *upper = lower + m;

    while (lower != first + m && upper != last) {
        if (*lower < *upper) {
            *(result++) = *(lower++);
            continue;
        }

        *(result++) = *(upper++);
        TotalInversions += ((first + m) - lower);
    }

    while (lower != first + m)
        *(result++) = *(lower++);

    while (upper != last)
        *(result++) = *(upper++);

    for (I i = 0; i < n; i++) {
        *(first + i) = v[i];
    }

    TotalInversions += LeftSubarrayInversions + RightSubarrayInversions;

    return TotalInversions;
}

#endif
