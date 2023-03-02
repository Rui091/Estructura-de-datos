#include <stdio.h>
int main() {
    int nT = 0;
    int nI,i,j;
    int n[100] = {0};
    scanf("%d",&nI);
    for(i=0;i<nI;i++){
        int r=0;
        int valormin=1000;
        int valormax=-100;
        scanf("%d",&nT);
        for (j=0;j<nT;j++){
            scanf("%d",&n[i]);
            if (valormin>n[i]){
                valormin=n[i];
            }
            if(valormax<n[i]){
                valormax=n[i];
            }
        }
    r=(valormax-valormin)*2;
    printf("%d \n",r);
}
return 0;
}

