
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <string>

/*
Autor: Rui Yu Lei Wu
Codigo: 8978227


*/

using namespace std;
/*
Complejidad: La complejidad de este codigo es O(log n *m) donde n es el numero el tamano del mapa y m es el numero de elementos en
la pila, esto debido a que se hace una busqueda en el mapa en un ciclo donde se recorre la pila.

*/
void eliminarPosicionesPila(stack<int> &pil,list<int> &l){
    map<int,int> mapa;
    stack<int> pilAux;
    int contador=pil.size()-1;
    for(list<int>::iterator it=l.begin();it!=l.end();++it){
        if(!mapa[*it])
            mapa[*it]=1;
    }
    while(!pil.empty()){
        if(mapa[contador])
            pilAux.push(pil.top());
        --contador;
        pil.pop();
        
    }
    pil=pilAux;
}

/*
Complejidad: La complejidad es O(n) donde n es el numero de elementos de la cola, debido a que la solucion solo conlleva
condiciones que estan dentro de un ciclo qu recorre la cola.


*/
void verificarOrdenadoCola(queue<int> &q){
    int tmp=q.front();
    q.pop();
    int ordenado=3;
    bool bandera=true;
    while(!q.empty() && bandera==true){
        if(tmp>q.front()){
            if(ordenado!=1){
                ordenado=0;
            }
            else{
                bandera=false;
            }
        }
        else if(tmp<q.front()){
            if(ordenado!=0){
                ordenado=1;
            }
            else{
                bandera=false;
            }
        }
        tmp=q.front();
        q.pop();
    }
    if(bandera==true){
        if(ordenado==1)
            printf("Menor a mayor\n");
        else
            printf("Mayor a menor\n");
    }
    else{
        printf("Desordenado\n");
    }
}
/*
Complejidad: La complejidad es O(n) donde n es el numero de elementos en la lista, debido a que se itera hasta l.end()


*/

void obtenerMenorCosto(list<int> &l){
    l.sort();
    list<int>::iterator it=l.begin();
    int suma=*it+(*it+1);
    int costo=0;
    ++it;
    while(it!=l.end()){
        costo+=suma;
        suma+=*next(it);
        ++it;
    }
    printf("%d",costo);
}
/*
Complejidad: Es O(log n*m) donde n es el numero de elemntos del mapa, y m es el de la cola, es un ciclo que va hasta
que la cola este vacia y se hacen operaciones find en el mapa



*/

void verificarRepetidos(queue<int> &n){
    map<int,int> mapa;
    while(!n.empty()){
        if(!mapa[n.front()])
            mapa[n.front()]=1;
        else
            ++mapa[n.front()];
        n.pop();
    }
    map<int,int>::iterator it=mapa.begin();
    while (it!=mapa.end()) {
        if(it->second>1)
            cout<<it->first<<" se repite:"<<it->second<<" veces"<<endl;
        ++it;
    }
}
/*
Complejidad: Es O(log n*m) donde n son los elementos del mapa y m es el tamano de la cadena


*/

map<char,list<int>> obtenerPosicionesOcurrencias(string &cad){
    map<char,list<int>> mapa;
    for(int i=0;i<cad.size();++i){
        mapa[cad[i]].push_back(i);
    }
    return mapa;
}
/*
Complejidad: Es O(log n *m) la misma logica de las demas.


*/
bool verificarRepetidosCola(queue<int> &n){
    bool ans=false;
    map<int,int> mapa;
    while(!n.empty() && ans==false){
        if(!mapa[n.front()])
            mapa[n.front()]=1;
        else{
            ++mapa[n.front()];
            ans=true;
        }
        n.pop();
    }
    return ans;
}
bool esPar(int n){
    bool ans=false;
    if(n%2==0)
        ans=true;
    return ans;
}

/*
Complejidad: Es O(n) donde n son los elementos de la cola, debido a que hay un ciclo que va hasta el final de la cola.



*/

queue<int> filtrarNParesCola(queue<int> &q){
    queue<int> resultado;
    while(!q.empty()){
        if(esPar(q.front())){
            resultado.push(q.front());
        }
        q.pop();
    }
    return resultado;
    
}





int main() {
    queue<int> n;
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(1);
    n.push(1);
    n.push(2);
    
    

	return 0;
}