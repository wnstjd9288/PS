#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
long long int dp[5001][5001];
long long int ps[5001];
int main()
{
    int n;
    int open = 0, close = 0;
    char s[5001];
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            open++;
        else
        {
            ps[i] = 1;
            close++;
        }
        if (i)
            ps[i] += ps[i - 1];
    }
    if (open && s[0] == '(')
        dp[1][0] = 1;
    if (close)
        dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = ps[i - 1]; j <= i; j++)
        {
            if (close >= j)
            {
                dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod) % mod;
            }
        }
    }
    // printf("o: %d / c: %d\n", open, close);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //         printf("%3d ", dp[i][j]);
    //     puts("");
    // }
    printf("%lld", dp[n][close]);
}