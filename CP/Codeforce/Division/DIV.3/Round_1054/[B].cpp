#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        vector<int> arr;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            arr.push_back(a);
        }
        int m=-1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i+=2){
            m=max(m,abs(arr[i]-arr[i+1]));
        }
        printf("%d\n",m);
    }
}