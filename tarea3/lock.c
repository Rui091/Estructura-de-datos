#include <stdio.h>

int main() {
    int pos, com1, com2, com3;
    scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
    while(!(pos==0 && com1==0 && com2==0 && com3==0)){
        int rotacionNecesaria=0;
        if(pos<com1){
            rotacionNecesaria+=40;
            }
        if(com2<com1){
            rotacionNecesaria+=40;
            }
        if(com2<com3){
            rotacionNecesaria+=40;
            }
        rotacionNecesaria+=(((pos-com1)+(com2-com3)+(com2-com1)));
        rotacionNecesaria*=9;
        printf("%d\n",rotacionNecesaria+1080);
        scanf("%d %d %d %d",&pos, &com1, &com2, &com3);
        }
    return 0;
}


