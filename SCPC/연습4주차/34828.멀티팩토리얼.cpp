#include <bits/stdc++.h>
#define mod 998244353
typedef long long int ll;
using namespace std;
ll dp[100001][401];
int main()
{
    int n;
    for (int i = 1; i <= 400; i++)
        dp[1][i] = 1;
    for (ll i = 2; i <= 100000; i++)
    {
        for (ll j = 1; j <= 400; j++)
        {
            dp[i][j]=i;
            if (i - j > 0)
                dp[i][j] = (dp[i - j][j] * i) % mod;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if (b <= 400)
        {
            printf("%lld\n", dp[a][b]);
            continue;
        }
        ll result = 1;
        while (a > 0)
        {
            result = (result * a) % mod;
            a -= b;
        }
        printf("%lld\n", result);
    }
}