#include <vector>
#include <string>
/*
Proyecto: Archivo.h
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/
#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

using namespace std;

class BigInteger{
	private:
		vector<int> vec;
		
	public:
		BigInteger(string num);
		BigInteger();
		BigInteger(const BigInteger &n);
		void add(BigInteger n);
		void product(BigInteger n);
		void substract(BigInteger n);
		void quotient(BigInteger n);
		void remainder(BigInteger n);
		void pow(BigInteger n);
		string toString();
		
		
		BigInteger operator+(BigInteger n);
		BigInteger operator-(BigInteger n);
		BigInteger operator*(BigInteger n);
		BigInteger operator/(BigInteger n);
		BigInteger operator%(BigInteger n);
		bool operator==(BigInteger n);
		bool operator<(BigInteger n);
		bool operator<=(BigInteger n);
		
		
};
#endif
