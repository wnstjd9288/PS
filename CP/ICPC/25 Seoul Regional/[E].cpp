#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int big[5001], small[5001];
bool is_leaf[5001];
int n;
long long int result;
int DFS(int now, int parent)
{
    if (graph[now].size() == 1 && parent)
    {
        big[now] = 1;
        is_leaf[now] = true;
        return 1;
    }
    vector<pair<int, int>> direct_child;
    for (auto child : graph[now])
    {
        if (child == parent)
            continue;
        direct_child.push_back({DFS(child, now), child});
    }
    sort(direct_child.begin(), direct_child.end());
    int size = direct_child.size();
    for (int i = 0; i < size; i++)
    {
        int temp = big[now];
        big[now] = small[now];
        small[now] = temp;
        result += small[direct_child[i].second] + 1 + big[now];
        big[now] += direct_child[i].first;
    }
    return big[now] + small[now] + 1;
}
int main()
{
    scanf("%d", &n);
    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1, 0);
    printf("%lld", result);
}