#include <bits/stdc++.h>
#define MOD 998244353LL
int main()
{
    int n;
    long long int res = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        long long int a;
        scanf(" %c %lld", &c, &a);
        res = ((res % MOD) * ((a + 1) % MOD)) % MOD;
    }
    printf("%lld", (res - 1 + MOD) % MOD);
}