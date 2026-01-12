#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
char s[1000001];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#' || !dp[i])
            continue;
        if (i + 1 < n && s[i + 1] != '#')
            dp[i + 1] = 1;
        if (i + k < n && s[i + k] != '#')
            dp[i + k] = 1;
    }
    if (dp[n - 1])
        printf("YES");
    else
        printf("NO");
}