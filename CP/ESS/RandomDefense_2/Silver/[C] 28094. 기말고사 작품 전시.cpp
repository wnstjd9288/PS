#include <bits/stdc++.h>
using namespace std;
int n, m;
int score[10][10];
int res = -1;
int cnt = 0;
void work(int visited[], int point, int depth, int now)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            point += score[i][now];
        }
    }
    if (depth == n)
    {
        if (point > res)
        {
            res = point;
            cnt = 1;
        }
        else if (point == res)
            cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            work(visited, point, depth + 1, i);
            visited[i] = 0;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int visited[10] = {
            0,
        };
        res = -1;
        cnt = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                score[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++)
        {
            int v, a, b;
            scanf("%d%d%d", &v, &a, &b);
            score[a][b] += v;
        }
        work(visited, 0, 0, 0);
        printf("%d %d\n", res, cnt);
    }
    return 0;
}