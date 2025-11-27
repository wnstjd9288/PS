#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int a=0,b=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int k;
            scanf("%d",&k);
            if(k==-1)a++;
            else if(k==0)b++;
        }
        a%=2;
        if(a)b+=2;
        printf("%d\n",b);
    }
}