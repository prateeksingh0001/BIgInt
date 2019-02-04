#include "../src/merge.h"
#include <fstream>
#include <vector>

using namespace std;

int main(){
    
    int num[100000];
    fstream int_list;
    int number ;

    int_list.open("integer_list.txt");

    for(int i=0; i<100000; i++){
        int_list>>number ;
        num[i] = number ;
    }
    
    int n = sizeof(num)/sizeof(num[0]);

    int num_inversions = mergesort(num, num+n );
    
    cout<<num_inversions<<endl ;

    return 0;
    
}
