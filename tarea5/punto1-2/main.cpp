#include "lista.h"


int contarOcurrencias(Lista &l,int v){
	int ans;
	if (l.vaciaLista()){
		ans=0;
	}
	else{
		int i=1;
		while(i<=l.longLista()){
			if(l.infoLista(i)==v){
				++ans;
			}
			++i;
		}
	}
	return ans;
}
Lista obtenerMenores(Lista &l,int v){
	Lista ans;
	if((l.vaciaLista())){
			printf("Lista vacia");
	}
	else{
		int i=1;
		while(i<=l.longLista()){
			int elemento=l.infoLista(i);
			if(elemento<v){
				ans.anxLista(elemento);
			}
			++i;
		}
	}	
	return ans;
}

int main(){
  Lista l;
  l.anxLista(3);
  l.anxLista(3);
  l.anxLista(3);
  l.anxLista(7);
  l.anxLista(14);
  l.anxLista(3);
  l.anxLista(8);
  l.anxLista(9);
  
  Lista l2 = obtenerMenores(l,7);
  int r = contarOcurrencias(l,3);
  return 0;
	
}