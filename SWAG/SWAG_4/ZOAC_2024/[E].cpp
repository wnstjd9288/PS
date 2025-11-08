#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<pair<int, int>, pair<int, int>>,
               vector<pair<pair<int, int>, pair<int, int>>>,
               greater<pair<pair<int, int>, pair<int, int>>>>
    pq;                                              // {{weight, tp}, {x,y}}
vector<vector<vector<pair<int, pair<int, int>>>>> g; // {weight,{x,y}}
int arr[101][101];
int visited[1001][101][101];
int n, m, k, t, q;
void Dijkstra(int x, int y)
{
    visited[t][x][y] = 0;
    pq.push({{0, t}, {x, y}});
    while (!pq.empty())
    {
        pair<pair<int, int>, pair<int, int>> now = pq.top();
        pq.pop();
        pair<int, int> xy = now.second;
        for (int i = 0; i < g[xy.first][xy.second].size(); i++)
        {
            pair<int, pair<int, int>> next = g[xy.first][xy.second][i];
            if (next.first == -1)
            {
                if (now.first.second)
                {
                    if (visited[now.first.second - 1][next.second.first][next.second.second] > now.first.first)
                    {
                        visited[now.first.second - 1][next.second.first][next.second.second] = now.first.first;
                        pq.push({{now.first.first, now.first.second - 1}, {next.second.first, next.second.second}});
                    }
                }
            }
            else
            {
                if (visited[now.first.second][next.second.first][next.second.second] > now.first.first + next.first)
                {
                    visited[now.first.second][next.second.first][next.second.second] = now.first.first + next.first;
                    pq.push({{now.first.first + next.first, now.first.second}, {next.second.first, next.second.second}});
                }
            }
        }
    }
}

int main()
{
    pair<int, int> xy[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    scanf("%d%d%d%d%d", &n, &m, &k, &t, &q);
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        g[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int a = 0; a <= t; a++)
                visited[a][i][j] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int a = 0; a < 4; a++)
            {
                pair<int, int> next = {i + xy[a].first, j + xy[a].second};
                if (next.first <= 0 || next.first > n || next.second <= 0 || next.second > m)
                    continue;
                g[i][j].push_back({arr[next.first][next.second], next});
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        g[a][b].push_back({-1, {c, d}});
        g[c][d].push_back({-1, {a, b}});
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("{%d, %d} -> ", i, j);
            for (int a = 0; a < g[i][j].size(); a++)
            {
                printf("{%d, {%d, %d}} ", g[i][j][a].first, g[i][j][a].second.first, g[i][j][a].second.second);
            }
            puts("");
        }
    }
*/
    Dijkstra(1, 1);
    /*
    for (int a = t; a >= 0; a--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%3d ", visited[a][i][j]);
            }
            puts("");
        }
        puts("");
    }
    */
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        bool flag = false;
        scanf("%d%d%d", &a, &b, &c);
        for (int j = 0; j <= t; j++)
        {
            if (visited[j][b][c] <= a)
            {
                flag = true;
                break;
            }
        }
        printf("%d\n", flag ? 1 : 0);
    }
    return 0;
}