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


// Online C compiler to run C program online

int main() {
    int x,y ;
    int k=0;
    int i=0;
    scanf("%d",&k);
    while (i<k){
        scanf("%d %d",&x,&y);
        if (x==0 || y==0 ){
            printf("divisa \n");
        }
        else if (x<0 && y>0){
            printf("NO \n");
        }
        else if (x<0 && y<0){
            printf("SO \n");
        }
        else if (x>0 && y>0){
            printf("NE \n");
        }
        else if (x>0 && y<0){
            printf("SE \n");
        }
        else if (x==0 && y==0){
            i==k;
        }
        
        i++;
    }

    return 0;
}