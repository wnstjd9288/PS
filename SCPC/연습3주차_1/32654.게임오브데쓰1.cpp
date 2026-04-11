#include <bits/stdc++.h>
int dp[101][1001];
int player[1001][2];
int main()
{
    int n;
    scanf("%d", &n);
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int L, R;
        scanf("%d%d", &L, &R);
        player[i][0] = L;
        player[i][1] = R;
    }
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i - 1][player[j][0]] || dp[i - 1][player[j][1]])
                dp[i][j] = 1;
        }
    }
    int res = -1;
    for (int i = 10; i < 100; i++)
    {
        if (!dp[i][1])
        {
            res = i;
            break;
        }
    }
    printf("%d", res);
}