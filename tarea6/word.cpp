#include <iostream>
#include <map>
#include <list>
#include <string>

/*
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/
/*
Complejidad: La complejidad es O(nlogn) debido a que las operaciones del mapa son siempre nlogn.

*/

using namespace std;

int main() {
    string str;
    list<string> l;
    getline(cin,str);
    l.push_back(str);
    while(str!="#"){
        getline(cin,str);
        l.push_back(str);
    }
    string letras;
    getline(cin,letras);
    while (letras[0]!='#'){
        int contador=0;
        map<char,int>mapa;
        for(int i=0; i<letras.size();++i){
            if (letras[i]!=' '){
                if (!mapa[letras[i]]){
                    mapa[letras[i]]=1;
                } 
                else{
                    ++mapa[letras[i]];
                }
            }
        }
        for(list<string>::iterator it=l.begin();it!=l.end();++it){
            map<char,int>mapAux(mapa.begin(), mapa.end());
            int i=0;
            bool bandera=true;
            while(i<it->size() && bandera==true){
                if(mapAux[(*it)[i]]>0 && mapAux[(*it)[i]] ){
                    --mapAux[(*it)[i]];
                }
                else if(mapAux[(*it)[i]]<0 || !mapAux[(*it)[i]]){
                    bandera=false;
                }
                ++i;
            }
            if(bandera==true){
                ++contador;
            }
        }
        printf("%d\n",contador);
        getline(cin,letras);
        
    }
    return 0;
}