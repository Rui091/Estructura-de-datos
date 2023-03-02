#include <stdio.h>
int main() {
    int arr[3000];
    while (scanf("%d",&arr[0])!=EOF){
        int i=1;
        int x=2;
        int ans;
        int k=0;
        int j=1;
        int jolly=1;
        int bandera=0;
        int arr2[arr[0]];
        for(i=1;i<=arr[0];i++){
            scanf("%d",&arr[i]);
        
        }
        for (k=0;k<=arr[0];k++){
            arr2[k]=0;
        }
        for (x=2;x<=arr[0];x++) {
            ans = (arr[x]-arr[x-1]);
            if (ans < 0) {
                ans= ans*-1;
                
            }
            if (ans <= arr[0]) {
                arr2[ans]=1;
            }
        }
        while (j<arr[0] && bandera==0){
            if (arr2[j]==1){
                jolly=1;
                
            }
            else{
                jolly=0;
                bandera=1;
            }
            j++;
            }
        
        if (jolly==1){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        
        }
    }
   return 0;
}