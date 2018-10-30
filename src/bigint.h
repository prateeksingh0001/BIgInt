#ifndef BIGINT_H
#define BIGINT_H
	

#include <iostream>
#include <string>

using namespace std ;

class BigInt{

	string num ;

public:
	BigInt();
	BigInt(string str) ;

	int length;
	bool isPositive ;

	BigInt operator + (BigInt);
	BigInt operator * (BigInt &);
	BigInt operator - (BigInt);
	int operator >(BigInt);
	bool operator == (BigInt);

	void removeLeadingZeros() ;
	int makeEqualLength(BigInt &);
	void print(){ cout<<num<<endl ;}
	
};


#endif 