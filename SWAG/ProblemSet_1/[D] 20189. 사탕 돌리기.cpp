#include <bits/stdc++.h>
long long candy[2001][2001] = {
    0,
};
int main()
{
    long long n, k, q;
    long long cnt = 0;
    scanf("%lld %lld %lld", &n, &k, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int a;
            scanf("%d", &a);
            candy[i][a]++;
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (i <= j)
                cnt += candy[i][j] * (j - i);
            else
                cnt += candy[i][j] * (n - (i - j));
        }
    }
    if (candy[1][1] == k)
        cnt += n;
    if (cnt / n > q)
        printf("0");
    else
        printf("1");

    return 0;
}