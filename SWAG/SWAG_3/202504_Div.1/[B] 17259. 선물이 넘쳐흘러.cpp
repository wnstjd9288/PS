#include <bits/stdc++.h>
using namespace std;
int factory[1002][1002] = {0};
vector<pair<int, int>> worker;
int timer[1002][1002] = {0};
int visited[1002][1002] = {0};
int main()
{
    int b, n, m;
    scanf("%d%d%d", &b, &n, &m);
    int res = m;
    for (int i = 0; i < n; i++)
    {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        factory[x][y + 1] = t;
        worker.push_back({x, y + 1});
    }
    for (int i = 0; i < 3 * b + m; i++)
    {
        for (int j = 0; j < worker.size(); j++)
        {
            // printf("timer %d, factory %d\n", timer[worker[j].first][worker[j].second], factory[worker[j].first][worker[j].second]);
            if (timer[worker[j].first][worker[j].second] == factory[worker[j].first][worker[j].second])
                timer[worker[j].first][worker[j].second] = 0;
            visited[worker[j].first][worker[j].second] = 0;
        }
        if (i < m)
            factory[0][0] = -1;
        else
            factory[0][0] = 0;
        // printf("%d start, res: %d\n", i, res);
        // for (int j = 0; j < b; j++)
        // {
        //     for (int k = 1; k <= b; k++)
        //     {
        //         printf("%2d ", factory[j][k]);
        //     }
        //     puts("");
        // }
        if (factory[b - 1][0] == -1)
        {
            res--;
        }
        for (int j = 0; j <= b - 1; j++)
        {
            factory[b - 1][j] = factory[b - 1][j + 1];
            if (timer[b - 2][j])
            {
                if (!visited[b - 2][j])
                {
                    visited[b - 2][j] = 1;
                    timer[b - 2][j]++;
                }
                continue;
            }
            if (factory[b - 1][j] == -1 && !timer[b - 2][j] && factory[b - 2][j])
            {
                factory[b - 1][j] = 0;
                timer[b - 2][j]++;
                visited[b - 2][j] = 1;
            }
        }
        for (int j = b - 1; j > 0; j--)
        {
            factory[j][b] = factory[j - 1][b];
            if (j == b - 1)
                continue;
            if (timer[j][b - 1])
            {
                if (!visited[j][b - 1])
                {
                    visited[j][b - 1] = 1;
                    timer[j][b - 1]++;
                }
                continue;
            }
            if (factory[j][b] == -1 && !timer[j][b - 1] && factory[j][b - 1])
            {
                factory[j][b] = 0;
                timer[j][b - 1]++;
                visited[j][b - 1] = 1;
            }
        }
        for (int j = b; j > 0; j--)
        {
            factory[0][j] = factory[0][j - 1];
            if (j == b)
                continue;
            if (timer[1][j])
            {
                if (!visited[1][j])
                {
                    visited[1][j] = 1;
                    timer[1][j]++;
                }
                continue;
            }
            if (factory[0][j] == -1 && !timer[1][j] && factory[1][j])
            {
                factory[0][j] = 0;
                timer[1][j]++;
                visited[1][j] = 1;
            }
        }
        // printf("%d end, res: %d\n", i, res);
        // for (int j = 0; j < b; j++)
        // {
        //     for (int k = 1; k <= b; k++)
        //     {
        //         printf("%2d ", factory[j][k]);
        //     }
        //     puts("");
        // }
    }
    printf("%d", res);
}
