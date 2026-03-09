#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return 0;
}