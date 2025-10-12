#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int ltl[100001] = {
    0,
};
void DFS(int now, int parent)
{
    if (tree[now].size() == 1 && tree[now][0] == parent)
    {
        ltl[now] = 1;
        return;
    }
    bool flag = true;
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i] == parent)
            continue;
        DFS(tree[now][i], now);
        if (ltl[tree[now][i]] == 1)
            flag = false;
    }
    ltl[now] = flag ? 1 : 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%s\n", ltl[i]?"uppercut":"ddongggas");
}