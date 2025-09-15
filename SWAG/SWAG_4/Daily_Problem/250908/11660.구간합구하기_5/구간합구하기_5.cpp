#include <bits/stdc++.h>
int map[1025][1025] = {
    0,
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] += map[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[j][i] += map[j - 1][i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x1, x2, y1, y2, result = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        result += map[x2][y2] + map[x1 - 1][y1 - 1] - map[x2][y1 - 1] - map[x1 - 1][y2];
        printf("%d\n", result);
    }
}