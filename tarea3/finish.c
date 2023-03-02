#include <stdio.h>

int main() {
    int casos;
    int i;
    scanf("%d",&casos);
    for (i=1;i<=casos;i++){
        int n;
        scanf("%d",&n);
        int x=0;
        int k=0;
        int j=0;
        int arr1[n];
        int arr2[n];
        int gas=0;
        int estacion=0;
        int distancia=0;
        int totalGas=0;
        int totalDistancia=0;
        int encontrado=0;
        for(x=0;x<n;x++) {
            scanf("%d", &arr1[x]);
            totalGas+=arr1[x];
        }
        for (k=0;k<n;k++){
            scanf("%d",&arr2[k]);
            totalDistancia+=arr2[k];
        }
        while (j<n && totalGas>=totalDistancia){
            if (arr1[j]>=arr2[j] || encontrado==1){
                distancia+=arr2[j];
                gas+=arr1[j];
                if (encontrado==0){
                    estacion=j+1;
                    encontrado=1;
                }
                if (distancia>gas){
                    gas=0;
                    distancia=0;
                    encontrado=0;
                }
            }
            j++;
        }
        if(estacion!=0){
            printf("Case %d: Possible from station %d\n",i,estacion);
        }
        else{
            printf("Case %d: Not possible\n", i);
            }
    }
    return 0;
}