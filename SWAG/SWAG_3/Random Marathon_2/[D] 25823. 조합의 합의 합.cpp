#include <bits/stdc++.h>
long long mod = 1000000007;
long long int mul(long long int y)
{
    if (y == 1)
    {
        return b % mod;
    }
    long long int k = mul(y / 2) % mod;
    if (y % 2 == 0)
    {
        return k * k % mod;
    }
    else
        return k * k % mod * b % mod;
}

int main()
{
    int m;
    long long cal=6;
    long long sum = 0;
    scanf("%d", &m);
    for (int n = 3; n <= m; n++)
    {
        
    }
    printf("%lld", sum);
}