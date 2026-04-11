#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int check[200001];
int a, b, x;
void DFS(int now, int parent)
{
    if (now == x)
        return;
    check[now] = 1;
    if (parent && graph[now].size() == 1)
    {
        return;
    }
    for (int i = 0; i < graph[now].size(); i++)
    {
        if (graph[now][i] == parent)
            continue;
        DFS(graph[now][i], now);
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    graph.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    scanf("%d%d%d", &a, &b, &x);
    DFS(a, 0);
    DFS(b, 0);
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=check[i];
    }
    printf("%d",n-cnt);
}