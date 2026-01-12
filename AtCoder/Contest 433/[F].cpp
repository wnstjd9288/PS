#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int news[1000001];
int num[1000001];
int non[10];
int dp[10][1000001];
int main()
{
    int n;
    int prev = -1;
    int idx = 1;
    int cnt = 1;
    long long int res = 0;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        non[s[i] - '0']++;
        dp[s[i] - '0'][i]++;
        for (int j = 0; j < 10; j++)
        {
            dp[j][i + 1] = dp[j][i];
        }
    }
    
    printf("%lld", res);
}