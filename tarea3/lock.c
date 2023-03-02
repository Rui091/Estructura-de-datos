#include <stdio.h>

int main() {
    int pos, com1, com2, com3;
    scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
    int terminar=0;
    while(terminar==0){
        if (pos==0 && com1==0 && com2==0 && com3==0){
            terminar=1;
        }
        else{
            int rotacionNecesaria=0;
            if(pos<com1){
                pos+=40;
            }
            if(com2<com1){
                com2+=40;
            }
            if(com2<com3){
                com2+=40;
            }
            rotacionNecesaria=(((pos-com1)+(com2-com1)+(com2-com3))*9)+1080;
            printf("%d\n",rotacionNecesaria);
            scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
        }
        
    }

 return 0;
}