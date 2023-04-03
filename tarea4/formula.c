#include <stdio.h>

/*RUI YU LEI WU, CÓDIGO:8978227*/
/*La complejidad de la solución en el peor de los casos  
es O(n^2) que seria cuando existe el mismo
numero de carreras que de conductores, debido a que la solucion depende
de dos ciclos anidados que recorren la matriz cYL*/
int main() {
    int conductores;
    int carreras;
    int i,j,k,x,z,c,v,n;
    scanf("%d %d",&carreras, &conductores);
    while(carreras!=0 && conductores!=0){
        int numSistemas;
        int numPremiados;
        int sistemas[conductores];
        int cYL[500][100];
        for(i=0;i<carreras;i++){
            j=0;
            while(j<conductores){
                scanf("%d",&cYL[j][i]);
                j++;
            }
        }
        scanf("%d",&numSistemas);
        for(k=0;k<numSistemas;k++){
            int pilotos[500];
            int puntuacionGanador=0;
            scanf("%d",&numPremiados);
            for(x=0;x<numPremiados;x++){
                scanf("%d",&sistemas[x]);
            }
            for(z=0;z<conductores;z++){
                for(c=0;c<carreras;c++){
                    int pos=cYL[z][c]-1;
                    if(pos < numPremiados){
                        pilotos[z]+=sistemas[pos];
                    }
                }
            }
            
            int numGanadores=0;
            for(v=0;v<conductores;v++){
                if(pilotos[v]>puntuacionGanador){
                    puntuacionGanador=pilotos[v];
                    numGanadores=1;
                }
                else if(pilotos[v]==puntuacionGanador){
                    numGanadores++;
                    
                }
            }
            int nimpresiones=0;
            for(n=0;n<conductores;n++){
                if(numGanadores!=1){
                    if(pilotos[n]==puntuacionGanador && nimpresiones<(numGanadores-1)){
                        printf("%d ",n+1);
                        nimpresiones++;
                }
                    else if(pilotos[n]==puntuacionGanador && nimpresiones==(numGanadores-1)){
                        printf("%d",n+1);
                        nimpresiones++;
                    }
                }
                else{
                    if(pilotos[n]==puntuacionGanador){
                            printf("%d",n+1);
                        }
                    }
                pilotos[n]=0;
                }
            nimpresiones=0;
            printf("\n");
            }
        scanf("%d %d",&carreras, &conductores);    
        }    
    return 0;
}
        