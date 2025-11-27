#include <bits/stdc++.h>
using namespace std;
long long int arr[1001][1001][2];
long long int dp[1001][1001][2];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &arr[i][j][0]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &arr[i][j][1]);
        }
    }
    dp[1][1][0] = dp[1][1][1] = arr[1][1][0];
    for (int i = 2; i <= n; i++)
    {
        dp[i][1][0] = dp[i][1][1] = dp[i - 1][1][0] + arr[i][1][0];
        if (arr[i][1][1])
        {
            dp[i][1][0] = dp[i][1][1] = -dp[i][1][0];
        }
    }
    for (int i = 2; i <= m; i++)
    {
        dp[1][i][0] = dp[1][i][1] = dp[1][i - 1][0] + arr[1][i][0];
        if (arr[1][i][1])
            dp[1][i][0] = dp[1][i][1] = -dp[1][i][0];
    }
    // dp[0]=min dp[1]=max
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (arr[i][j][1])
            {
                dp[i][j][0] = -(max(dp[i - 1][j][1], dp[i][j - 1][1]) + arr[i][j][0]);
                dp[i][j][1] = -(min(dp[i - 1][j][0], dp[i][j - 1][0]) + arr[i][j][0]);
            }
            else
            {
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + arr[i][j][0];
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + arr[i][j][0];
            }
        }
    }
    printf("%lld", dp[n][m][1]);
    return 0;
}