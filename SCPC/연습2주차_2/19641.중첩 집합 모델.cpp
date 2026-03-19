#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<pair<int, int>> range;
int n, root;
int tree(int now, int parent, int start)
{
    if (parent && graph[now].size() == 1)
    {
        range[now] = {start, start + 1};
        return 2;
    }
    int sum = 1;
    for (int i = 0; i < graph[now].size(); i++)
    {
        if (graph[now][i] == parent)
            continue;
        int k = tree(graph[now][i], now, start + sum);
        sum += k;
    }
    range[now] = {start, start + sum};
    return sum+1;
}
int main()
{
    scanf("%d", &n);
    graph.resize(n + 1);
    range.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d", &a);
        for (int j;; j++)
        {
            scanf("%d", &b);
            if (b == -1)
                break;
            graph[a].push_back(b);
        }
    }
    scanf("%d", &root);
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    tree(root, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d %d\n", i, range[i].first, range[i].second);
    }
}