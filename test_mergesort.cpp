#include <iostream>
#include <fstream>
#include "src/merge.h"

using namespace std;

int main()
{

    int array[100000];
    fstream int_list;
    int number;

    int_list.open("coursera_assignments/integer_list.txt");

    for (int j = 0; j < 100000; j++) {
        int_list >> number;
        array[j] = number;
    }

    int n = sizeof(array) / sizeof(array[0]);

    long long int inversions = mergesort<int, long long int>(array, array + n);

    cout << endl << "Total number of inversion = " << inversions << endl;
    return 0;
}
