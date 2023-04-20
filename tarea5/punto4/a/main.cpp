#include "lista.h"
#include "lista.cpp"
//O(n^2)
void concatenarListas(Lista &l,Lista &l2){
	int i=1;
	while(i<=l2.longLista()){
		l.anxLista(l2.infoLista(i));
		++i;
		}
}

int main(){
  Lista l;
  Lista l2;
  l.anxLista(3);
  l.anxLista(1);
  l.anxLista(2);
  
  l2.anxLista(10);
  l2.anxLista(11);
  l2.anxLista(12);
  l2.anxLista(13);
  l2.anxLista(14);
  l2.anxLista(15);
  concatenarListas(l,l2);
  for(int i=1;i<=l.longLista();i++){
  	printf("%d ",l.infoLista(i));
  }
  return 0;

}
