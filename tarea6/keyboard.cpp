#include <iostream>
#include <list>
#include <string>

/*
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/
/* 
Complejidad: La complejidad es O(n) donde n es el tamaño de la cadena.

*/
using namespace std;

int main() {
    int j;
    string cadena="";
    
    while(getline(cin,cadena)){
        list<string> l;
        for(int i=0;i<cadena.size();++i){
            string str1="";
            if(cadena[i]=='['){
                ++i;
                while(cadena[i]!=']' && cadena[i]!='[' && i!=(cadena.size())){
                    str1.push_back(cadena[i]);
                    ++i;
                }
                l.push_front(str1);
                
            }
            else if(cadena[i]!=']'){
                    l.push_back(string(1, cadena[i]));
            }
            if(cadena[i]=='['){
                --i;
            }
        }
        for (list <string>::iterator it=l.begin();it!=l.end();++it){
            if(it==--l.end())
                cout<<*it<<endl;
            else{
                cout<<*it;
            }
        }
        cadena="";
    }
    return 0;
}