#include <iostream>
#include <stack>
#include <list>

/*
Autor: Rui Yu Lei Wu
Codigo: 8978227
*/
/*
Complejidad: La complejidad es O(n) donde n es el numero de trenes.
*/

using namespace std;


int main() {
    int n;
    scanf("%d",&n);
    while(n!=0){
        list<int> l;
        stack<int> st;
        int x;
        bool bandera=true;
        int i=0;
        while(i<n && bandera==true){
            cin>>x;
            if(x==0)
            	bandera=false;
			else{
				l.push_back(x);
			}	
			++i;
        }
        while(x!=0){
        	stack<int> st;
            int i=1;
            list<int>::iterator it=l.begin();
            while(i<=n && it!=l.end()){
                if(*it==i){
                    ++it;
                    ++i;
                    }
                else if(*it!=i){
                    if(!st.empty() && *it!=st.top()){
                        st.push(i);
                        ++i;
                    }
                    else if(!st.empty() && *it==st.top()){
                        st.pop();
                        ++it;
                    }
                    else if(st.empty()){
                        st.push(i);
                        ++i;
                    }

                }
                while(!st.empty() && *it==st.top()){
                        st.pop();
                        ++it;
                    }
            }
            l.clear();
            if(st.empty()){
                printf("Yes\n");
            }
            if(!st.empty()){
                printf("No\n");
            }
            i=0;
            while(i<n && bandera==true){
            	cin>>x;
            	if(x==0){
            		bandera=false;
            		printf("\n");
				}
				else{
					l.push_back(x);
				}	
				++i;
       		}
        }
        scanf("%d",&n);
    }
    return 0;
}