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
vector<vector<pair<int, long long int>>> graph;
long long int dist[200001], INF = LONG_LONG_MAX;
void Dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, cmp> pq;
    pq.push({start, 0LL});
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
    }
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    Dijkstra(1);
    long long int res = INF;

    for (int i = 0; i < x; i++)
    {
        if (dist[e[i]] == INF)
            continue;

        long long int d = dist[e[i]];
        long long int cycle = x * k;
        long long int start = i * k;
        long long int end = (i + 1) * k;

        long long int incycle = d % cycle;

        long long int a;

        if (incycle < end)
        {
            if (incycle < start)
            {
                a = d + (start - incycle);
            }
            else
            {
                a = d;
            }
        }
        else
        {
            a = d + (cycle - incycle + start);
        }

        res = min(res, a);
    }
    printf("%lld", res);
}