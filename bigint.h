#include <iostream>
#include <string.h>

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
	bool operator == (BigInt);

	void removeLeadingZeros() ;
	int makeEqualLength(BigInt &);
	void print(){ cout<<num<<endl ;}
	
};

BigInt::BigInt(){;}

BigInt::BigInt(string str1){
	num = str1;
	length = num.length() ;
}

BigInt BigInt::operator + (BigInt num1){
	int carry = 0;
	string res="";
	
	int n = max(num1.length, this->length);

	for(int k=0; k<n; k++){
		
		if(k >= num1.length)
			carry += this->num[this->length - 1 - k] - '0';
		
		else if(k >= this->length)
			carry += num1.num[num1.length - 1 - k] - '0';
		
		else
			carry += (num1.num[num1.length - 1 - k] - '0') + (this->num[this->length - 1 - k] - '0');

		char digit = '0' + (carry%10);
		res = digit + res ;
		carry /= 10;
	}

	if(carry > 0){
		string x = to_string(carry);
		return BigInt(x+res);
	}
	else 
		return BigInt(res);
}

BigInt BigInt::operator * (BigInt &num1){
	//Uses the recursive KARATSUBA multiplication algorithm
	
	int n = this->makeEqualLength(num1);

	if (this->length == 0)
		return BigInt("0") ;

	else if(this->length == 1){
		int res = (this->num[0] - '0')*(num1.num[0] - '0');
		return BigInt(to_string(res)) ;
	}

	BigInt l1, l2, r1, r2 ;
	string exp1 = "1" ;
	string exp2 = "1" ;

	int half = n/2 ; 

	l1 = BigInt(this->num.substr(0, half));
	l2 = BigInt(num1.num.substr(0, half));

	r1 = BigInt(this->num.substr(half, n-half));
	r2 = BigInt(num1.num.substr(half, n-half));

	BigInt P1 = l1 * l2;
	BigInt P2 = r1 * r2;
	BigInt P3 = BigInt((l1 * r2) + (l2 * r1));

	for(int i =0; i<n ; i++)
		P1.num.push_back('0') ;
	P1.length = P1.num.length();

	for(int i =0; i<(n - half); i++)
		P3.num.push_back('0') ;
	P3.length = P3.num.length();

	BigInt add = P1 + P3;
	BigInt res = add + P2;

	res.removeLeadingZeros() ;
	return res ;
}

BigInt BigInt::operator -(BigInt num1){

}

int BigInt::makeEqualLength(BigInt &num1){
	int len1 = num1.length ;
	int len2 = this->length ;

	if (len1 < len2){
		for(int i =0; i< len2-len1; i++)
			num1.num = '0' + num1.num ;
		num1.length = num1.num.length() ;
		return len2 ;
	}
	else if(len2 < len1){
		for(int i=0; i< len1-len2; i++)
			this->num = '0' + this->num ;
		this->length = this->num.length() ;
		return len1 ;
	}
}

void BigInt::removeLeadingZeros(){
	this->num.erase(0, this->num.find_first_not_of('0'));
	this->length = this->num.length() ;
}

bool BigInt::operator == (BigInt num1){
	if(this->num == num1.num)
		return true;
	else 
		return false;
}