#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
queue<int> que;
int visited[300001];

void Dijkstra(int start)
{
    int h = -1, t = -1;
    que.push(start);
    visited[start] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (visited[now] + 1 < visited[next])
            {
                visited[next] = visited[now] + 1;
                que.push(next);
            }
        }
    }
}

int main()
{
    int n, m, k, x;
    bool flag = true;
    scanf("%d%d%d%d", &n, &m, &k, &x);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = INT_MAX;
    }
    Dijkstra(x);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == k)
        {
            flag = false;
            printf("%d\n", i);
        }
    }
    if (flag)
        printf("-1");
}