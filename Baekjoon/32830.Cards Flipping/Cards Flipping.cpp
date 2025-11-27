#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> cnt, m;
int p[1000001], f[200001], b[200001];
int visited[1000001];
int Find(int v)
{
    return v == p[v] ? v : p[v] = Find(p[v]);
}
bool Merge(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    p[u] = v;
    return true;
}
void BFS(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (visited[next])
                continue;
            visited[next] = 1;
            q.push(next);
            Merge(now, next);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 1000000; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
        scanf("%d", &f[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        graph[f[i]].push_back(b[i]);
        graph[b[i]].push_back(f[i]);
    }
    for (auto [x, y] : graph)
        if (!visited[x])
            BFS(x);

    for (auto [x, y] : graph)
        m[Find(x)]++;
    for (int i = 0; i < n; i++)
    {
        cnt[Find(f[i])]++;
    }
    long long int res = 0;
    for (auto [x, y] : cnt)
    {
        res += y > m[x] ? m[x] : y;
    }
    printf("%lld",res);
}