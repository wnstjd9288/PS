#include <bits/stdc++.h>

int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int n, m;
        int a;
        int res = 0;
        int train[101] = {
            0,
        };
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            train[a]++;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            if (train[a])
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}