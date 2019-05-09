#include <iostream>
#include <fstream>
#include "../src/quick_sort.h"

using namespace std;

int main()
{

    int array1[10000];
    int array2[10000];
    int array3[10000];
    //int array[] = {25, 22, 1, 39, 8, 4, 3, 2, 99};
    //int array[] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
    fstream int_list;
    fstream sorted_list;
    int number;
    
    int_list.open("coursera_assignments/quicksort.txt");
    sorted_list.open("sorted_res.txt", ios::out);

    for (int j = 0; j < 10000; j++) {
        int_list >> number;
        //cout<<number<<endl;
        array1[j] = number;
        array2[j] = number;
        array3[j] = number;
    }

    int n = sizeof(array1) / sizeof(array1[0]);
    //cout<<n<<endl;

    /*for(int i=0; i<n; i++){
        cout<<array[i]<<endl ;
    }*/

    long long int inversionsf = quicksort<int, long long int>(array1, 0, n-1);
    long long int inversionsl = quicksort<int, long long int>(array2, 0, n-1, 'l');
    long long int inversions3 = quicksort<int, long long int>(array3, 0, n-1, 'm');

    cout << "Total number of comparisons with f = " << inversionsf << endl;
    cout << "Total number of comparisons with l = " << inversionsl << endl;
    cout << "Total number of comparisons with m = " << inversions3 << endl;

    /*for(int i=0; i<n; i++){
        cout<<array3[i]<<endl;
        sorted_list<<array3[i]<<endl;
    }*/
    
    /*for(int i=0; i<n; i++){
        cout<<array[i]<<"  ";*
    }*/

    int_list.close();
    sorted_list.close();

    return 0;
}
