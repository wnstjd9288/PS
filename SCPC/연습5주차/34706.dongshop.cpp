#include <bits/stdc++.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            printf("%d %d\n",(n+1)/2,i);
        }
    }
}