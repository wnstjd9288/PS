#include <bits/stdc++.h>
using namespace std;
int arr[101][2];
double dp[101][2];
int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }
    dp[0][0] = sqrt(1 + abs(m - arr[0][0])); // start a
    dp[0][1] = sqrt(1 + abs(m - arr[0][1])); // start b
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i][0] - arr[i - 1][0]) > abs(arr[i][0] - arr[i - 1][1]))
            dp[i][0] = dp[i - 1][1] + sqrt(1 + abs(arr[i][0] - arr[i - 1][1]));
        else
            dp[i][0] = dp[i - 1][0] + sqrt(1 + abs(arr[i][0] - arr[i - 1][0]));

        if (abs(arr[i][1] - arr[i - 1][0]) > abs(arr[i][1] - arr[i - 1][1]))
            dp[i][1] = dp[i - 1][1] + sqrt(1 + abs(arr[i][1] - arr[i - 1][1]));
        else
            dp[i][1] = dp[i - 1][0] + sqrt(1 + abs(arr[i][1] - arr[i - 1][0]));
    }
    printf("%lf %lf\n",dp[n-1][0],dp[n-1][1]);
    return 0;
}