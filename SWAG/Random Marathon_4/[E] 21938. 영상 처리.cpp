#include <bits/stdc++.h>
int n, m;
int map[1001][1001] = {
    0,
};
int main()
{
    int t, res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                int x;
                scanf("%d", &x);
                sum += x;
            }
            map[i][j] = sum;
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = map[i][j] >= t * 3 ? 1 : 0;
            printf("%d ", map[i][j]);
        }
        puts("");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j])
        }
    }
}