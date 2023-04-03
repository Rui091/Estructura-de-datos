#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*RUI YU LEI WU, CÓDIGO:8978227*/
/*COMPLEJIDAD SOLUCION: En el peor caso, el programa es O(n^2) debido a que existe la posibilidad de que cuando la palabra1 sea mas larga se de que el while principal este anidado con
el while encontrado en el 2do condicional(principal) donde ambos ciclos iteran hasta el final de la palabra1(en el peor de los casos).
*/


int main() {
    int invitados,i,x,mediana;
    scanf("%d",&invitados);
    while (invitados!=0) {
        int j=0;
        mediana=invitados/2;
        string ans;
        vector<string> nombres(invitados);
        for (i=0;i<invitados;i++) {
            cin >> nombres[i];
        }
        sort(nombres.begin(),nombres.end());
        string palabra1=nombres[mediana-1];
        string palabra2=nombres[mediana];
        int bandera=0;
        
        while(j<palabra1.size() && bandera==0){
                if(palabra1[j]==palabra2[j]){
                    ans+=palabra1[j];
                }
                else if(palabra1[j]<palabra2[j]){
					if(palabra1.size()<=palabra2.size()){
							if(palabra1[j]+1<palabra2[j]){
								if(palabra1.size()-1==j){
                        			ans+=palabra1[j];
								}
								else{
									bandera=1;
									ans+=palabra1[j]+1;
								}
                        		
                    		}
                    		else if(palabra1[j]+1==palabra2[j]){
                        		if(palabra1.size()-1==j){
                        			ans+=palabra1[j];
								}
								else{
									ans+=palabra1[j]+1;
								}
                    		} 
						}
					else if(palabra1.size()>palabra2.size()){
							int k=j;
							int bandera2=0;
							while(k<palabra1.size() && bandera2==0){
								if(palabra1[k]+1==palabra2[j]){
									if(palabra1.size()-1==k){
										bandera2=1;
                        				ans+=palabra1[k];
									}
									else {
										if(palabra2.size()-1==k && palabra1[j]!='Z'){
											if(palabra1[k]>palabra2[j] && palabra2.size()-1==j){
												ans+=palabra1[k];
												
												}
											else{
												if (palabra1[k+1]>palabra2[j] && palabra1[k+1]!='Z'){
													bandera2=1;
													ans+=palabra1[k];
													ans+=palabra1[k+1]+1;
													}
												else{
													ans+=palabra1[k];
												}
								
										}
									}
										else{
											ans+=palabra1[k]+1;
											bandera2=1;
											}
									}
								}
								else{
									if(palabra1[k]=='Z'){
										ans+=palabra1[k];
									}
									else if(palabra1[k]<=palabra2[j]){
										ans+=palabra1[k]+1;
										bandera2=1;
										}
									else if(palabra1[k]>palabra2[j]){
											ans+=palabra1[k];
											bandera2=1;
										}
									}
									k++;
								}
								
							}
						}
						
                    
				if(palabra1<=ans && ans<=palabra2){
                    	bandera=1;
						}
                
                j++;
            }
            
        cout << ans << endl;
        scanf("%d",&invitados);
    }
	return 0;
}