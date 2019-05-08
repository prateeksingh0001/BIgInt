#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

template <typename T>
void swap(T *first, T *second){
    T temp = *first;
    *first = *second;
    *second = temp;
}


/*
 * With the below templates we are making the assumption that the 
 * datatype for indexing and the return type of the number of 
 * comparisons to be equal. 
 */

template <typename I, typename R>
R partition(I *array, R low, R high){
    
    I pivot = array[low];
    R i = low;

    for(R j=low+1; j<=high; j++){
        if ( array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[i]);
    return i;
}

template <typename I, typename R>
R quicksort(I *array, R low, R high){

    //std::cout<<"reached here"<<std::endl;

    if(high-low+1 <= 1){
        //std::cout<<"diff = "<<(high-low+1)<<std::endl;
        return high-low+1;
    }
    else if(low < high){
        R totalComparisons = high-low;
        R pivot_pos = partition<I, R>(array, low, high);

        /*for(R i=low; i<=high; i++){
            std::cout<<array[i]<<"  ";
        }*/
        //std::cout<<std::endl ;
        //std::cout<<"Pivot position = "<<pivot_pos<<std::endl;   
        
        return totalComparisons + quicksort<I, R>(array, low, pivot_pos-1) + quicksort<I, R>(array, pivot_pos+1, high);
    }
}

/*
* Made a very in line 49 strong assumption that TotalInversion is of datatype int or of similar types
* or of size_t, which is very bad and need a good alternative for that.
*/
#endif

/*
 * TODO: * Current algo works on the array itself and not a copy of it, should that be done ?
 */
