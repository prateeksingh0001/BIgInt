#include "bigint.h"
#include "bigint_exception.h"

BigInt::BigInt()
{
    BigInt("0");
}

int BigInt::length()
{
    return this->num.length();
}

// Make a constructor for taking int input

BigInt::BigInt(string str1)
{
    num = str1;
}

// Create a function for conversion from BigInt to int

BigInt BigInt::operator+(BigInt num1)
{
    int carry = 0;
    string res = "";

    int n = max(num1.length(), this->length());

    for (int k = 0; k < n; k++) {
        if (k >= num1.length())
            carry += this->num[this->length() - 1 - k] - '0';

        else if (k >= this->length())
            carry += num1.num[num1.length() - 1 - k] - '0';

        else
            carry += (num1.num[num1.length() - 1 - k] - '0')
                     + (this->num[this->length() - 1 - k] - '0');

        char digit = '0' + (carry % 10);
        res = digit + res;
        carry /= 10;
    }

    if (carry > 0) {
        string x = to_string(carry);
        return BigInt(x + res);
    } else
        return BigInt(res);
}

BigInt BigInt::operator*(BigInt &num1)
{
    // Uses the recursive KARATSUBA multiplication algorithm

    int n = this->makeEqualLength(num1);

    if (this->length() == 0)
        return BigInt("0");

    else if (this->length() == 1) {
        int res = (this->num[0] - '0') * (num1.num[0] - '0');
        return BigInt(to_string(res));
    }

    BigInt l1, l2, r1, r2;

    int half = n / 2;

    l1 = BigInt(this->num.substr(0, half));
    l2 = BigInt(num1.num.substr(0, half));

    r1 = BigInt(this->num.substr(half, n - half));
    r2 = BigInt(num1.num.substr(half, n - half));

    BigInt P1 = l1 * l2;
    BigInt P2 = r1 * r2;
    BigInt P3 = BigInt((l1 * r2) + (l2 * r1));

    for (int i = 0; i < n; i++)
        P1.num.push_back('0');

    for (int i = 0; i < (n - half); i++)
        P3.num.push_back('0');

    BigInt add = P1 + P3;
    BigInt res = add + P2;

    res.removeLeadingZeros();
    return res;
}

// Handle the not implemented error
int BigInt::operator>(BigInt num1)
{
    this->removeLeadingZeros();
    num1.removeLeadingZeros();

    if (*this == num1)
        return 0;
    else {
        if (this->length() > num1.length())
            return 1;

        else if (this->length() == num1.length()) {
            for (int i = 0; i < this->length(); i++) {
                if ((this->num[i] - '0') > (num1.num[i] - '0'))
                    return 1;
                else if ((this->num[i] - '0') < (num1.num[i] - '0'))
                    return -1;
            }
        }

        return -1;
    }
}

BigInt BigInt::operator-(BigInt num1)
{
    if (*this == num1)
        return BigInt("0");

    else if ((*this > num1) > 0) {
        int borrow = 0;
        int n = this->length();
        int result = 0;

        string res = "";

        for (int k = 0; k < n; k++) {
            result = (this->num[this->length() - 1 - k] - '0') - borrow;
            if (k >= num1.length()) {
                borrow = 0;
            } else {
                result -= (num1.num[num1.length() - 1 - k]
                           - '0'); // Make a function for single digit character
                                   // to string private function
                if (result < 0) {
                    result += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
            }
            char digit = '0' + result;
            res = digit + res;
        }
        return BigInt(res);
    } else
        throw NotImplementedError("Unhandled subtraction of signed integers");
}

int BigInt::makeEqualLength(BigInt &num1)
{
    // Make a copy  and return that copy
    // Both if conditions are doing identical stuff put them into a single
    // function

    int len1 = num1.length();
    int len2 = this->length();

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++)
            num1.num = '0' + num1.num;
        return len2;
    } else if (len2 < len1) {
        for (int i = 0; i < len1 - len2; i++)
            this->num = '0' + this->num;
        return len1;
    }
}

void BigInt::removeLeadingZeros()
{
    this->num.erase(0, this->num.find_first_not_of('0'));
}

bool BigInt::operator==(BigInt num1)
{
    if (this->num == num1.num)
        return true;
    else
        return false;
}