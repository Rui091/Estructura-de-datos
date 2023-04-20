#include "lista.h"
#include "lista.cpp"
//O(n^2)
void insertarEnListaOrdenada(Lista &l,int v){
	if(l.vaciaLista() || v-1==l.longLista()){
		l.anxLista(v);
	}
	else{
		int i=1;
		int bandera=0;	
		while(i<=l.longLista() && bandera==0){
			if(l.infoLista(i)>v){
				l.insLista(v,i);
				bandera=1;
			}
			++i;
		}
		if (bandera==0){
			l.anxLista(v);
		}
	}
}

int main(){
  Lista l;
  l.anxLista(0);
  l.anxLista(1);
  l.anxLista(3);
  l.anxLista(5);
  l.anxLista(7);
  l.anxLista(9);
  
  insertarEnListaOrdenada(l,2);
  insertarEnListaOrdenada(l,4);
  insertarEnListaOrdenada(l,6);
  insertarEnListaOrdenada(l,8);
  for(int i=1;i<=l.longLista();i++){
  	printf("%d ",l.infoLista(i));
  }
  return 0;
	
}
