#include <stdio.h>
int dp[100001][2] = {
    0,
};
int s1[100001][2];
int s2[100001][2];
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n;
        scanf("%d", &n);
        scanf("%d %d %d %d", &dp[0][0], &dp[0][1], &dp[n - 1][0], &dp[n - 1][1]);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n - 1; j++)
            {
                scanf("%d", &s1[j][i]);
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n - 1; j++)
            {
                scanf("%d", &s2[j][i]);
            }

        for (int i = 0; i < n - 1; i++)
        {
            dp[i + 1][0] += min(dp[i][0] + s1[i][1], dp[i][1] + s2[i][0]);
            dp[i + 1][1] += min(dp[i][0] + s1[i][0], dp[i][1] + s2[i][1]);
        }
        printf("%d\n", min(dp[n - 1][0], dp[n - 1][1]));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
                dp[i][j] = s1[i][j] = s2[i][j] = 0;
        }
    }
    return 0;
}