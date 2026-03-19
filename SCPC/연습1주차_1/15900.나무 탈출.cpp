#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
long long int sum = 0;
void game(int now, int parent, long long int cnt)
{
    if (tree[now].size() == 1 && now != 1)
    {
        sum += cnt;
        return;
    }
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i] == parent)
            continue;
        game(tree[now][i], now, cnt + 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    game(1, 0, 0);
    if (sum % 2)
        printf("Yes");
    else
        printf("No");
}