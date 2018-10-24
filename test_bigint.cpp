#include <iostream>
#include <assert.h>
#include "bigint.h"

using namespace std;

int main(){
	BigInt x1("23");
	BigInt x2("23");
	BigInt x3("200");
	BigInt x4("27182818284590452353602874713") ;
	BigInt x5("3141592653589793238462643383279502884197169399375105820974944592");
	BigInt x6("2718281828459045235360287471352662497757247093699959574966967627");
	BigInt add_x5x6("5859874482048838473822930854632165381954416493075065395941912219");
	BigInt mul_x5x6("8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184");

 	//comparison Tests
	if (x1 == x2)
		cout<<"COMPARISON TESTS PASSED...."<<endl ;
	else
		cout<<"Debug Comparison tests!!!!"<<endl ;

	//Addition Test
	BigInt sum_x5x6 = x5 + x6;

 	if(sum_x5x6 == add_x5x6)
 		cout<<"ADDITION TEST PASSED...."<<endl;
 	else
 		cout<<"Add needs debugging"<<endl;

 	//makeEqual Tests
 	int len = x2.makeEqualLength(x3);
 	if(len == x2.length)
 		cout<<"MAKE EQUAL LENGTH TEST PASSED...."<<endl ;
 	else 
 		cout<<"makeEqualLength needs debugging"<<endl ;

 	BigInt prod_x5x6 = x5 * x6 ;
 	if(prod_x5x6 == mul_x5x6)
 		cout<<"MULTIPLICATION TEST PASSED...."<<endl;
 	else
 		cout<<"WRONG ANSWER"<<endl ;

 	int a = x2 > x1 ;
 	cout<<a<<endl ;

 	BigInt sub = x3 - x2 ;
 	sub.print() ;

 	// BigInt x7("199") ;
 	// BigInt res("1") ;

 	// for(int i=0; i<199; i++){
 	// 	res = res * x7 ;
 	// }

 	// res.print();

	return 0 ;
}

