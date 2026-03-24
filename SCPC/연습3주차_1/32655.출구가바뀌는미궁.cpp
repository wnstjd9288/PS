#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, long long int> a, pair<int, long long int> b)
    {
        return a.second > b.second;
    }
};

long long int n, m, k, x;
vector<int> e;
vector<long long int> e_t;
vector<vector<pair<int, long long int>>> graph;
long long int dist[200001], INF = LONG_LONG_MAX;
void Dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> pq;
    pq.push({start, 0});
    while (!pq.empty())
    {
        int now = pq.top().first;
        long long int distance = pq.top().second;
        pq.pop();
        if (dist[now] < distance)
            continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            long long int nd = graph[now][i].second + distance;
            if (nd < dist[next])
            {
                dist[next] = nd;
                pq.push({next, nd});
            }
        }
    }
}
int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long int w;
        scanf("%d%d%lld", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    scanf("%lld", &x);
    for (long long int i = 1; i <= x; i++)
    {
        int a;
        scanf("%d", &a);
        e.push_back(a);
        e_t.push_back(i * k);
    }
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    Dijkstra(1);
    long long int res = INF;
    for (long long int i = 0; i < x; i++)
    {
        long long int a = INF;
        if (dist[e[i]] == INF)
            continue;
        if (dist[e[i]] < e_t[i] - k)
        {
            a = e_t[i] - k;
        }
        else if (e_t[i] - k <= dist[e[i]] && dist[e[i]] < e_t[i])
        {
            a = dist[e[i]];
        }
        else if (dist[e[i]] >= e_t[i])
        {
            long long int b = (dist[e[i]] - e_t[i]) / (x * k) + 1;
            a = e_t[i] - k + x * k * b;
            printf("%d %d %d\n%d\n", e[i], b, e_t[i] - k,a);
        }
        res = min(res, a);
    }
    printf("%lld", res);
}