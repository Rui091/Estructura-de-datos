#include "lista.h"
#include "lista.cpp"

int main(){

	Lista l;
	l.insListaOrdenada(1);
	l.insListaOrdenada(1);
	
	for(int i=1;i<=l.longLista();i++){
		printf("%d ",l.infoLista(i));
  }

	return 0;


}