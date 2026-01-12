#include <bits/stdc++.h>
using namespace std;
long long int dp[100001];
int main()
{
    int n;
    int mod = 1e9 + 7;
    scanf("%d", &n);
    dp[1] = 1;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i / 2] = ((dp[i / 2 - 1] % mod) * ((i - 1) % mod)) % mod;
    }
    printf("%lld", dp[n / 2]);
}