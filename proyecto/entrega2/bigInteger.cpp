#include "BigInteger.h"
#include <string>
#include <iostream>
#include <vector>
/*
Proyecto: Archivo.cpp
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/

using namespace std;
/*
Constructor 
Entrada: Un string.
Salida: Un BigInteger que representa el string volteado.
Descripción: Esta funcion convierte un string a una instancia BigInteger, esto principalmente recorriendo el string desde
el tamano del mismo hasta 0.

*/

BigInteger::BigInteger(const string &num){
	int size=num.size();
	if(num[0]=='-'){
        vec.push_back(0);
        for(int i=size-1;i>0;--i){
            vec.push_back(num[i]-'0');
        }
    }
    else{
    	vec.push_back(1);
    	for(int i=size-1;i>=0;--i){
            vec.push_back(num[i]-'0');
    	}
	}
    
}
/*
Constructor 
Salida: Un BigInteger vacio.
*/
BigInteger::BigInteger(){
	
}
/*
Constructor 
Entrada: Un Biginteger
Salida: Un BigInteger con los mismos elementos de el Bigintger de entrada
Descripción: Esta funcion copia los elementos del Vector de un Biginteger en otro Vector del Biginteger de salida

*/
BigInteger::BigInteger(const BigInteger &n){
	vec=n.vec;
}
/*
Suma
Entrada: Dos BigInteger
Salida: Un BigInteger que contiene la suma entre los dos BigInteger de entrada
Descripción: Usa la funcion add para sumar ambos numeros.

*/


BigInteger BigInteger::operator+(BigInteger &n){
	BigInteger resultado(*this);
	resultado.add(n);
	return resultado;
}
/*
Resta
Entrada: Dos BigInteger
Salida: Un BigInteger que contiene la resta entre los dos BigInteger de entrada
Descripción: Usa la funcion substract para restar ambos numeros.

*/

BigInteger BigInteger::operator-(BigInteger &n){
	BigInteger resultado(*this);
	resultado.substract(n);
	return resultado;
}
/*
Multiplicacion
Entrada: Dos BigInteger
Salida: Un BigInteger que contiene el producto entre los dos BigInteger de entrada
Descripción: Usa la funcion product para multiplicar ambos numeros.

*/
BigInteger BigInteger::operator*(BigInteger &n){
	BigInteger resultado(*this);
	resultado.product(n);
	return resultado;
	
}
/*
Quotient
Entrada: Dos BigInteger
Salida: Un BigInteger que contiene el cociente entre los dos BigInteger de entrada
Descripción: Usa la funcion quotient para dividir ambos numeros.

*/
BigInteger BigInteger::operator/(BigInteger &n){
	BigInteger resultado(*this);
	resultado.quotient(n);
	return resultado;
	
}
/*
Remainder
Entrada: Dos BigInteger
Salida: Un BigInteger que contiene el residuo entre los dos BigInteger de entrada
Descripción: Usa la funcion remainder para dividir ambos numeros.

*/

BigInteger BigInteger::operator%(BigInteger &n){
	BigInteger resultado(*this);
	resultado.remainder(n);
	return resultado;
	
	
}
/*
Reduce ceros
Entrada: Un BigInteger
Salida: Un BigInteger sin ceros a la derecha
Descripción: Elimina ceros de mas en un BigInteger

*/
void BigInteger::reduceCeros(){
	while(vec.back()==0){
		vec.pop_back();
	}

}
/*
==
Entrada: Dos BigInteger
Salida: True o False
Descripción: Determina si dos BigIntegers son o no iguales

*/
bool BigInteger::operator==(BigInteger &n){
	bool ans=true;
	int i=0;
	
	if(vec.size()!=n.vec.size()){
		ans=false;
	}
	else{
		while(i<vec.size() && ans==true){
			if(vec[i]!=n.vec[i]){
				ans=false;
			}
			++i;
		}
		
	}
	return ans;
	
}
/*
<
Entrada: Dos BigInteger
Salida: True o False
Descripción: Determina si n es mayor a un Biginteger ejemplo: a<b

*/
bool BigInteger::operator<(BigInteger &n){
	bool ans=true;
	bool bandera=true;
	int size=vec.size();
	int i=size-2;
	int size2=n.vec.size();
	if(size==size2){
		if(vec[size-1]>n.vec[size-1]){
			if(vec[0]==1)
				ans=false;
			else if(vec[0]==0 && n.vec[0]==0 && vec[size-1]<n.vec[size-1])
				ans=false;
				
		}
		else if(vec[size-1]==n.vec[size-1]){
			if(vec[0]==1 && n.vec[0]==0){
				ans=false;
			}
			else if((vec[0]==1 && n.vec[0]==1) || (vec[0]==0 && n.vec[0]==0)){
				while(i>0 && bandera==true){
					if(vec[i]!=n.vec[i]){
						bandera=false;
						if (vec[0]==1){
							if(vec[i]>n.vec[i]){
								ans=false;		
							}
						}
						else if(vec[0]==0){
							if(vec[i]<n.vec[i]){
								ans=false;		
							}
						}
					}
					--i;
				}
				if(bandera==true){
					ans=false;
				}
			}
		}	
	}
	else if(size>size2){
		if(vec[0]==1)	
			ans=false;	
	}
	else if(size<size2){
		if(vec[0]==1 && n.vec[0]==0)
			ans=false;
		else if(vec[0]==0 && n.vec[0]==0)
			ans=false;
	}
	
	return ans;
	
}
/*
<=
Entrada: Dos BigInteger
Salida: True o False
Descripción: Determina si n es mayor o igual a un Biginteger ejemplo: a<=b

*/
bool BigInteger::operator<=(BigInteger &n){
	bool ans=false;
	if((*this<n)==1 || (*this==n)==1){
		ans=true;
	}
	return ans;
	
}
/*
OrganizarVec
Entrada: Un vector
Salida: El vector organizado como un BigInteger
Descripción: Recibe un vector "desorganizado", y lo organiza correctamente 

*/
vector<int> organizarVec(vector<int>& v) {
    vector<int> resultado;
	resultado.push_back(1);
    for (int i=v.size()-1;i>=0;i--){
        if(v[i]==0){
            resultado.push_back(0);
        }
        else{
            while (v[i]>0){
                int digito=v[i]%10;
                resultado.push_back(digito);
                v[i]/=10;
            }
        }
        
    }
    return resultado;
}
/*
tostring
Entrada: Un Biginteger
Salida: Un string que representa el BigInteger
Descripción: Convierte una instacia BigInteger a un string esto para poder imprimirlo de manera facil

*/
	
string BigInteger::toString(){
	string num="";
	if(vec.size()<=1){
		num.push_back('0');
	}
	else{
		if(vec[0]==0){
			num.insert(0, 1, vec[vec.size() - 1] + '0');
			num.insert(0, 1, '-');
		}
		else{
			num.insert(0, 1, vec[vec.size() - 1] + '0');
		}
		for(int i=vec.size()-2;i>0;--i){
			num.push_back(vec[i]+'0');
			
		}
	}
	return num;
}
/*
add
Entrada: Dos BigInteger
Salida: Ejemplo: num.add(num2) en este caso la salida es el mismo num el cual contiene la suma o resta de ambos numeros
Descripción: Suma dos numeros de n digitos

*/
void BigInteger::add(BigInteger &n){
	int menor;
	int mayor;
	int num=0;
	int i=1;
	int suma=0;
	int residuo=0;
	int operacion=1;
	int signo=1;
	int signo2=1;
	if(vec.size()>=n.vec.size()){
		mayor=vec.size();
		menor=n.vec.size();
		if(vec[0]==0 && n.vec[0]==1){
		    operacion=0;
		    signo=0;
			}
		else if(vec[0]==1 && n.vec[0]==0){
		    operacion=0;
		    signo2=0;
        }
	}
	else{
		mayor=n.vec.size();
		menor=vec.size();
		if(vec[0]==0 && n.vec[0]==1){
		    operacion=0;
        }
        else if(vec[0]==1 && n.vec[0]==0){
		    operacion=0;
		    signo=0;
		    signo2=0;
	    }
	    else if(vec[0]==0 && n.vec[0]==0){
        	signo=0;
        	signo2=0;
		}
	}
	if(operacion==0){
		vec[0]=1;
		n.vec[0]=1;
		this->substract(n);
	}
	else if(operacion==1){
		for(i=1;i<menor;++i){
			num=(vec[i]+n.vec[i]+residuo);
			vec[i]=(num%10);
			residuo=(num)/10;
			
		}
		if(mayor==i && residuo!=0){
			vec.push_back(residuo);
		}
		else{
			int suma2=0;
			while(residuo!=0 || i<mayor){
			    if(i<vec.size()){
			    	suma=(vec[i]+residuo);
			    	vec[i]=suma%10;
			        residuo=suma/10;
					}
				if(i>=mayor){
					vec.push_back(residuo);
					residuo=0;
				}
				else if(i<n.vec.size()){
					suma=(n.vec[i]+residuo);
					suma2=suma%10;
			        residuo=suma/10;
			        vec.push_back(suma2);
			    	}
			    ++i;
				}
		}  
	}
	if(signo==0){
        vec[0]=0;
    }
    else{
        vec[0]=1;
    }
    n.vec[0]=signo2;
}
/*
Substract
Entrada: Dos BigInteger
Salida: Ejemplo: num.substract(num2) en este caso la salida es el mismo num el cual contiene la suma o resta de ambos numeros
Descripción: Resta dos numeros de n digitos, similar a una resta en papel.

*/
void BigInteger::substract(BigInteger &n){
	int mayor;
	int menor;
	int mayorNum;
	int i;
	int operacion=0;
	int signo=1;
	int signo2=1;
	int tB=vec.size();
	int tn=n.vec.size();
	if(tB>=tn){
		mayor=tB;
		menor=tn;
		mayorNum=0;
	}
	else{
		mayor=tn;
		menor=tB;
		mayorNum=1;
	}
	if((vec[0]==1 && n.vec[0]==1) && mayorNum==1){
        signo=0;

    }
	else if((vec[0]==0 && n.vec[0]==0) && mayorNum==0){
        signo=0;
    }
    else if(vec[0]==0 && n.vec[0]==1){
        operacion=1;
        signo=0;
        vec[0]=0;
        n.vec[0]=0;
        signo2=1;
    }
    else if(vec[0]==1 && n.vec[0]==0){
        operacion=1;
        signo=1;
        vec[0]=1;
        n.vec[0]=1;
        signo2=0;
   
    }
    if(operacion==1){
        this->add(n);
    }
    else if(operacion==0){
		for(i=0;i<menor;++i){
			if(mayorNum==0){
				if(vec[i]>=n.vec[i]){
					vec[i]=vec[i]-n.vec[i];
				}
				else{
					--vec[i+1];
					vec[i]=(10+vec[i])-n.vec[i];
				}
			}
			else{
				 if(n.vec[i]>=vec[i]){
	                vec[i]=n.vec[i]-vec[i];
	            }
	            else{
	                --n.vec[i + 1];
	                vec[i] = (10 + n.vec[i]) - vec[i];
	            }
			}
		}
		if(mayorNum==1){
	        while(i<mayor){
	            if(n.vec[i]<0){
	                --n.vec[i+1];
	                n.vec[i]+=10;
	            }
	            vec.push_back(n.vec[i]);
	            ++i;
	        }
	    }
	    if(mayorNum==0){
	        while(mayorNum==0 && vec[i]<0){
	            --vec[i+1];
	            vec[i]=vec[i]+10;
	            ++i;
	        }
	    }
	    this->reduceCeros();
	}
	if(signo==1){
        vec[0]=1;
        
        }
    else if(signo==0){
        vec[0]=0;
        }
    n.vec[0]=signo2;
        
}
/*
Addceros
Entrada: un Biginteger y un contador
Salida: Un biginteger con n ceros
Descripción: Agrega ceros hasta llegar al contador

*/
void BigInteger::addCeros(int contador){
	for(int i=0;i<contador;++i){
		vec.push_back(0);
	}
}
/*
Product
Entrada: Dos BigInteger
Salida: Ejemplo: num.product(num2) en este caso la salida es el mismo num el cual contiene la multiplicacion de ambos numeros
Descripción: Multiplica dos numeros de n digitos, esto se hace con dos ciclos anidados y con la funcion addceros, para luego
realizar n sumas hasta que acaben ambos ciclos.

*/

void BigInteger::product(BigInteger &n){
	BigInteger resultado;
	BigInteger parcial;
	resultado.vec.push_back(1);
	int multiplicacion=0;
	int resultado2=0;
	int residuo=0;
	int signo=1;
	int signo2=1;
	int contador=0;
	if(vec[0]==0 && n.vec[0]==1){
		vec[0]=1;
	    signo=0;
	}
	else if(vec[0]==1 && n.vec[0]==0){
		n.vec[0]=1;
	    signo=0;
	    signo2=0;
	}
	for(int i=1;i<vec.size();++i){
		parcial.vec.push_back(1);
		parcial.addCeros(contador);
		++contador;
		for(int j=1;j<n.vec.size();++j){
			resultado2=vec[i]*n.vec[j];
			multiplicacion=(resultado2+residuo)%10;
			residuo=(resultado2+residuo)/10;
			parcial.vec.push_back(multiplicacion);
			}
	
		if(residuo!=0){
			parcial.vec.push_back(residuo);
			residuo=0;
		}
		resultado.add(parcial);
		parcial.vec.clear();

	}
	vec=resultado.vec;
	
	if(signo==1){
	    vec[0]=1;
	}
	else{
	    vec[0]=0;
	}
	n.vec[0]=signo2;
}
/*
Division
Entrada: Dos BigInteger
Salida: Ejemplo: num.division(num2,1 o 0) en este caso la salida es el mismo num el cual contiene el cociente o residuo de ambos numeros
Descripción: Divide dos numeros de n digitos, esto lo hace con restas que el dividendo sea menor al divisor.

*/

void BigInteger::division(BigInteger &n,int operacion){
	int signo=1;
	int signo2=1;
	int contadorCeros=0;
	vector<int> v;
	v.push_back(0);
	BigInteger contador;
	if(vec[0]==1 && n.vec[0]==0){
		signo=0;
		n.vec[0]=1;
		signo2=0;
	}
	else if(vec[0]==0 && n.vec[0]==1){
		signo=0;
		vec[0]=1;
	}
	if((*this<n)==0){
		while(vec.size()>n.vec.size()){
			n.vec.insert(n.vec.begin() + 1, 0);
			v.push_back(0);	
			++contadorCeros;	
		}
		int i=0;
		while((*this<n)==1){
			if(n.vec[1]==0){
				n.vec.erase(n.vec.begin()+1);
				v.erase(v.begin()+1);
				--contadorCeros;
			}
		}
		
		while((*this==n)==1 || ((*this<n)==0)){
			this->substract(n);
			++v[i];
			while((*this<n)==1 && contadorCeros!=0){
				n.vec.erase(n.vec.begin()+1);
				--contadorCeros;
				++i;	
			}	
		}
	if(operacion==1)
		vec=organizarVec(v);
	}
	else{
		if(operacion==1){
			vec.clear();
		}
	}
		
	
	
	if(signo==1){
	    vec[0]=1;
	}
	else{
	    vec[0]=0;
	}
	n.vec[0]=signo2;

}
	

void BigInteger::quotient(BigInteger &n){
	this->division(n,1);
}

void BigInteger::remainder(BigInteger &n){
	this->division(n,0);
}

/*
Pow
Entrada: Un BigInteger y un entero n
Salida: Eleva un BigInteger a una potencia n
Descripción: Multiplica (n/2)+1 o +2 un BigInteger

*/
void BigInteger::pow(int n) {
    if (n==0) {
        vec.clear();
        vec.push_back(1);
        vec.push_back(1);
    }
    else{
	    BigInteger num;
	    num.vec=vec;
	    for (int i=1;i<n/2;++i){
	        this->product(num);
	        
	    }
	    this->product(*this);
	    if(n%2!=0){
	    	this->product(num);
		}

	}
}
/*
sumarListaValores
Entrada: Una lista de BigInteger
Salida: Un Biginteger con la suma de la lista
Descripción: Suma todos los bigintegers de la lista

*/
BigInteger BigInteger::sumarListaValores(list<BigInteger> &l){
	BigInteger num;
	list<BigInteger>::iterator it=l.begin();
	num=*it+(*next(it));
	++it;
	++it;
	while(it!=l.end()){
		num=num+*it;
		++it;
		
	}
	return num;
	
}
/*
multiplicarlistaValores
Entrada: Una lista de BigInteger
Salida: Un Biginteger con la multiplicacion de la lista
Descripción: multiplica todos los bigintegers de la lista

*/

BigInteger BigInteger:: multiplicarListaValores(list<BigInteger> &l){
	BigInteger num;
	list<BigInteger>::iterator it=l.begin();
	num=*it*(*next(it));
	++it;
	++it;
	while(it!=l.end()){
		num=num*(*it);
		++it;
		
	}
	return num;
	
}

	