#include <bits/stdc++.h>
int cnt[3];
int loc[3];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int k;
            scanf("%d", &k);
            cnt[k - 1]++;
            loc[k - 1] = i * 3 + j;
        }
    }
    int a, b;
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] == n + 1)
            a = i + 1;
        if (cnt[i] == n - 1)
            b = i + 1;
    }
    printf("%d\n%d", b, a);
    return 0;
}