#include <stdio.h>

int main() {
    int pos, com1, com2, com3;
    scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
    while(!(pos==0 && com1==0 && com2==0 && com3==0)){
        int rotacionNecesaria=1080;
        if(pos<com1){
            pos+=40;
        }
        if(com2<com1){
            com2+=40;
        }
        if(com2<com3){
            com2+=40;
        }
        rotacionNecesaria+=(((pos-com1)+(com2-com1)+(com2-com3))*9);
        printf("%d\n",rotacionNecesaria);
        scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
    }
 return 0;
}