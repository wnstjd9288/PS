#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
long long int s[100001];
int parent[100001];
void DFS(int now, int pa)
{
    if (tree[now].size() == 0 && pa)
        return;
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i] == pa)
            continue;
        parent[tree[now][i]] = now;
        DFS(tree[now][i], now);
    }
}
void water(int now, long long int x)
{
    if (s[now] <= x)
    {
        x -= s[now];
        s[now] *= 2;
    }
    else
    {
        s[now] += x;
        return;
    }
    if (tree[now].size() == 1 && parent[now])
        return;
    if (!parent[now])
    {
        for (int i = 0; i < tree[now].size(); i++)
            water(tree[now][i], (long long int)x / tree[now].size());
    }
    else
    {
        for (int i = 0; i < tree[now].size(); i++)
        {
            if (tree[now][i] == parent[now])
                continue;
            water(tree[now][i], (long long int)x / (tree[now].size() - 1));
        }
    }
    return;
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int qn, u;
        long long int x;
        scanf("%d%d", &qn, &u);
        if (qn == 1)
        {
            scanf("%lld", &x);
            water(u, x);
        }
        else
        {
            printf("%lld\n", s[u]);
        }
    }
}