#include <bits/stdc++.h>
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n;
        long long arr[100001];
        long long G = 0;
        scanf("%d", &n);
        scanf("%lld", &arr[0]);
        G = arr[0];
        for (int i = 1; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            G = gcd(G, arr[i]);
        }
        for (int i = 2; i <= 100000; i++)
        {
            if (gcd(G, i) == 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}