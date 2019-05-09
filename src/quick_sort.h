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
R partitionWithFirst(I *array, R low, R high){
    
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
R partitionWithLast(I *array, R low, R high){

    I pivot = array[high];
    swap(&array[low], &array[high]);
    R pivot_position = partitionWithFirst<I, R>(array, low, high);

    return pivot_position;
}

template <typename I, typename R>
R partitionWithMedianofThree(I *array, R low, R high){

    R length = high - low + 1;
    R median_index;
    R pivot_position;

    if(length%2 == 0)
        median_index = (length/2)-1;
    else
        median_index = length/2;

    median_index += low;

    if((array[low]<=array[median_index] && array[median_index]<=array[high]) || (array[high]<=array[median_index] && array[median_index]<=array[low])){
        swap(&array[low], &array[median_index]);
    }
    else if((array[median_index]<=array[high] && array[high]<=array[low]) || (array[high]<=array[median_index] && array[low]<=array[high])){
        swap(&array[low], &array[high]);
    }
    
    pivot_position = partitionWithFirst<I, R>(array, low, high);

    return pivot_position;
}

template <typename I, typename R>
R quicksort(I *array, R low, R high, char pivot_type='f'){

    //std::cout<<"reached here"<<std::endl;

    if(high-low+1 <= 1){
        //std::cout<<"diff = "<<(high-low+1)<<std::endl;
        return 0;
    }
    else if(low < high){
        R totalComparisons = high-low;
        R pivot_pos ;

        switch(pivot_type){
            case 'f':
                pivot_pos = partitionWithFirst<I, R>(array, low, high);
                break;
            case 'l':
                pivot_pos = partitionWithLast<I, R>(array, low, high);
                break;
            case 'm':
                pivot_pos = partitionWithMedianofThree<I, R>(array, low, high);
        }
        
        /*for(R i=low; i<=high; i++){
            std::cout<<array[i]<<"  ";
        }*/
        //std::cout<<std::endl ;
        //std::cout<<"Pivot position = "<<pivot_pos<<std::endl;   
        
        return totalComparisons + quicksort<I, R>(array, low, pivot_pos-1, pivot_type) + quicksort<I, R>(array, pivot_pos+1, high, pivot_type);
    }
}

#endif

/*
 * TODO: * Refactor the code so that the arrays work by rearranging the pointers to each element and the not the elements itself.
 *         This approach has two benefits, first the original array will remain untouched and an array of pointer would be
 *         independent of the size of the data-structure it is pointing to and hence every element would always occupy same amount
 *         of space.
 *
 *       * Add an argument for the comparison function in the code of both mergesort and quicksort, this would enable this
 *         of these algos to work with any data structures, as long as a comparison function for those data structures is given.
 */
