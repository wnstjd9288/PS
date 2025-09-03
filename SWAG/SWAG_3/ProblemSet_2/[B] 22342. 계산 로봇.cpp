#include <bits/stdc++.h>
int map[2002][2002] = {
    0,
};
int dp[2002][2002] = {
    0,
};
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, m;
    int res = -1;
    std::pair<int, int> maxindex;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
        dp[i][1] = map[i][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                dp[j + k][i + 1] = max(dp[j + k][i + 1], map[j + k][i + 1] + dp[j][i]);
            }
            if (dp[j][i] - map[j][i] > res)
            {
                res = dp[j][i] - map[j][i];
                maxindex = std::make_pair(j, i);
            }
        }
    }
    printf("%d", res);
    return 0;
}