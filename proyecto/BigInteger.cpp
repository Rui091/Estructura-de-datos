#include 'BigInteger.h'
#include <string>
#include <iostream>
/*
Proyecto: Archivo.cpp
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/
BigInteger::BigInteger(string num){
	int size=num.size();
	for(int i=size-1;i>=0;--i){
		vec.push_back(stoi(num[i]));
	}
}
BigInteger::BigInteger(){
	
}



BigInteger BigInteger::operator+(BigInteger n){
	BigInteger x;
	int sizesmall;
	int bigsize;
	int sobrante=0;
	int suma=0;
	string numero;
	if(vec.size()>=n.vec.size()){
		sizesmall=n.vec.size();
		bigsize1=vec.size();
	}
	else{
		sizesmall=vec.size();
		bigsize=n.vec.size();
	}
	for(int i=0;i<sizesmall;++i){
		suma=((vec[i]+n.vec[i])%10)+sobrante);
		sobrante=(vec[i]+n.vec[i])/10;
		x.vec.push_back(suma);
	}
	if(bigsize>bigsize1){
		for(i;i<bigsize;++i){
			x.vec.push_back(n.vec[i]);
		}
	}
	else{
		for(i;i<bigsize1;++i){
			x.vec.push_back(vec[i]);
		}
	}
	return x;
}


BigInteger BigInteger::operator-(BigInteger n){
	BigInteger x;
	int resta=0;
	if(vec.size()>n.vec.size() && vec[vec.size()-1]>0){
		for(int i=0;i<n.vec.size();++i){
			if(n.vec[i]>vec[i]){
				resta=(vec[i]+10)-n.vec[i];
				vec[i+1]-1;
				
			}
		}
	}
	
	
}
bool BigInteger::operator==(BigInteger n){
	bool ans=true;
	int i=0;
	if(vec.size()!=n.vec.size()){
		ans=false;
	}
	else{
		while(i<vec.size && ans==true){
			if(vec[i]!=n.vec[i]){
				ans=false;
			}
			++i;
		}
		
	}
	return ans;
	
}
bool BigInteger::operator<(BigInteger n){
	bool ans=true;
	bool bandera=true;
	int size=vec.size();
	int i=size-2;
	int size2=n.vec.size();
	if(size==size2){
		if(vec[size-1]>n.vec[size-1]){
			ans=false;
		}
		if(vec[size-1]==n.vec[size-1]){
			while(i>=0 && bandera==true){
				if(vec[i]!=n.vec[i]){
					bandera=false;
					if(vec[i]>n.vec[i]){
						ans=false;
					}
				}
				--i;
			}
			if(bandera==true){
				ans=false;
			}
		}
		
	}
	else if(size>size2 && vec[size-1]>0){	
		ans=false;	
	}
	else if(size<size2 && n.vec[size2-1]<=0){
		if(vec[size-1]>0){
			ans=false;
		}
	}
	return ans;
	
}
string BigInteger::toString(){
	string num="";
	for(int i=vec.size-1;i>=0;--i){
		num+=to_string(vec[i]);
		
	}
}

