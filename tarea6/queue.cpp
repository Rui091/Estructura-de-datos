#include <iostream>
#include <map>
#include <utility>
#include <list>

/*
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/

/* 
Complejidad: La complejidad es O(nlogn) debido a que las operaciones de la lista son constantes, pero las operaciones que 
se hacen con el mapa son nlogn.

*/


using namespace std;

int main() {
    int n;
    int instrucciones;
    int pacientes;
    char instruccion;
    int contadorCasos=1;
    scanf("%d %d",&pacientes,&instrucciones);
    list<pair<int,int>> l;
    map<int,int> mapa;
    while(pacientes!=0 && instrucciones!=0){
    	l.clear();
    	mapa.clear();
        printf("Case %d:\n",contadorCasos);
        int menor;
        if(pacientes>=instrucciones){
            menor=instrucciones;
        }
        else{
            menor=pacientes;
        }
        for(int i=1;i<=menor;++i){
            mapa[i]=0;
            l.push_back(make_pair(i,0));
        }
        int j=1;
        while(j<=instrucciones){
        	cin>>instruccion;
        	if(instruccion=='E'){
            	scanf("%d",&n);
            }
            if(instruccion=='N'){
                if(l.front().second==mapa[l.front().first]){
                    cout<<l.front().first<<endl;
                    l.push_back(l.front());
                    l.pop_front();
                }
                else{
                    while(l.front().second!=mapa[l.front().first]){
	                    l.pop_front();
	                }
	                cout<<l.front().first<<endl;
	                l.push_back(l.front());
	                l.pop_front();
                }
            }
            else if(instruccion=='E'){
                if(mapa.find(n)!=mapa.end()){
                    ++mapa[n];
                    l.push_front(make_pair(n,mapa[n]));

                }
                else{
                    mapa[n]=0;
                    l.push_front(make_pair(n,0));
                }
            }
            
            ++j;
        }
        ++contadorCasos;
        scanf("%d %d",&pacientes,&instrucciones);
        
    }
    return 0;
}