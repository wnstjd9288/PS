#include <bits/stdc++.h>

int main()
{
    int n, k;
    int res;
    scanf("%d%d", &n, &k);
    if (n * 2 > k)
    {
        printf("-1");
        return 0;
    }
    res = k - (n - 1) * 2;
    if(res>=3)printf("%d",n*2);
    else printf("%d",k-1);
}