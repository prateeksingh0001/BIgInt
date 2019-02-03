#include <iostream>
#include "src/merge.h"

using namespace std ;

int main(){

    int array[] = {1, 49, 35, 30, 4, 10};
    int n = sizeof(array)/sizeof(array[0]) ; 

    cout<<"original array is:"<<endl ;
    for(int i =0; i<n; i++)
        cout<<array[i]<<" " ;
    cout<<endl ;

    mergesort <int> (*array, *array + n) ;

    for(int i =0; i<n; i++)
        cout<<array[i]<<"  ";

    return 0;
    
}


