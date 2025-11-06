#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
queue<int> q;
int mm;
int max_arr[10001];
int visited[10001];
void BFS(int start)
{
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!visited[next])
            {
                visited[next] = 1;
                q.push(next);
                mm++;
            }
        }
    }
    max_arr[start] = mm;
}
int main()
{
    int n, m, res = 0;
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        mm = 1;
        for (int j = 1; j <= n; j++)
            visited[j] = 0;
        BFS(i);
    }
    for (int i = 1; i <= n; i++)
        res = max_arr[i] > res ? max_arr[i] : res;
    for (int i = 1; i <= n; i++)
    {
        if (res == max_arr[i])
            printf("%d ", i);
    }
}