#include <bits/stdc++.h>
using namespace std;
struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

vector<vector<int>> graph;
vector<int> weight;
unordered_map<pair<int, int>, vector<int>, PairHash> pairmap;
int result = -1;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    weight.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d => ", i);
    //     for (auto [x, y] : childmap[i])
    //     {
    //         if (y)
    //             printf("%d ", x);
    //     }
    //     puts("");
    // }
    for (int i = 1; i <= n; i++)
    {
        if (!graph[i].empty())
            sort(graph[i].begin(), graph[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        int len = graph[i].size();
        for (int j = 0; j < len - 1; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                pairmap[{graph[i][j], graph[i][k]}].push_back(i);
            }
        }
    }
    for (auto &[x, y] : pairmap)
    {
        int len = y.size();
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                result = max(result, weight[x.first] + weight[x.second] + weight[y[i]] + weight[y[j]]);
            }
        }
    }
    printf("%d", result);
}