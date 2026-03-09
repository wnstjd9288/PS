#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<long long int> dist[2];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    dist[0].resize(n + 1);
    dist[1].resize(n + 1);
    for (int i = 0; i < n; i++)
        dist[1][i] = dist[0][i] = -1;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    return 0;
}