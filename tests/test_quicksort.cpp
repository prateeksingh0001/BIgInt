#include <iostream>
#include <fstream>
#include "../src/quick_sort.h"

using namespace std;

int main()
{

    int array[10000];
    //int array[] = {25, 22, 1, 39, 8, 4, 3, 2, 99};
    //int array[] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    fstream int_list;
    int number;

    int_list.open("nums.txt");

    for (int j = 0; j < 10000; j++) {
        int_list >> number;
        array[j] = number;
    }

    int n = sizeof(array) / sizeof(array[0]);
    cout<<n<<endl;

    long long int inversions = quicksort<int, long long int>(array, 0, n-1);

    cout << endl << "Total number of inversion = " << inversions << endl;
    
    /*for(int i=0; i<n; i++){
        cout<<array[i]<<"  ";
    }*/

    cout<<endl;

    return 0;
}
