
#include "BigInteger.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	string n = "3213578481";
    string num = "2";
    BigInteger num1(n);
    BigInteger num2(num);
    num1.quotient(num2);
	string impresi=num1.toString();
	cout<<impresi;


	return 0;
}