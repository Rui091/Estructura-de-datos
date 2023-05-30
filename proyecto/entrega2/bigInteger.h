
#include <list>
#include <string>
#include <vector>
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
		void addCeros(int contador);
		void reduceCeros();
		void division(BigInteger &n,int operacion);
		
	public:
		BigInteger(const string &num);
		BigInteger();
		BigInteger(const BigInteger &n);
		void add(BigInteger &n);
		void product(BigInteger &n);
		void substract(BigInteger &n);
		void quotient(BigInteger &n);
		void remainder(BigInteger &n);
		void pow(int n);
		string toString();
		
		static BigInteger sumarListaValores(list<BigInteger> &l);
		static BigInteger multiplicarListaValores(list<BigInteger> &l);
		
		BigInteger operator+(BigInteger &n);
		BigInteger operator-(BigInteger &n);
		BigInteger operator*(BigInteger &n);
		BigInteger operator/(BigInteger &n);
		BigInteger operator%(BigInteger &n);
		bool operator==(BigInteger &n);
		bool operator<(BigInteger &n);
		bool operator<=(BigInteger &n);
		
		
};
#endif
