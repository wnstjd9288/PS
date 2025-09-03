#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++)
    {
        long long map[101][101] = {
            0,
        };
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                    map[i][j] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                map[i][j] += map[i - 1][j] + map[i][j - 1];
            }
        }
        printf("Case #%d: %lld\n", test, map[n - 1][m - 1]);
    }
}