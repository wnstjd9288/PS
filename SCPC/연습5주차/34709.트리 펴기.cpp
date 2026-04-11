#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int cnt = 0;
void order(int now, int parent)
{
    if (tree[now].size() == 1 && parent)
        return;
    if (parent)
        cnt += tree[now].size() - 2;
    if (!parent && tree[now].size() >= 2)
        cnt += tree[now].size() - 2;
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i] == parent)
            continue;
        order(tree[now][i], now);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    order(1, 0);
    printf("%d",cnt);
}