#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<vector<pair<int, int>>> tree;
int result = 0;
int WeightTree(int now, int parent)
{
    if (tree[now].size() == 1 && tree[now][0].first == parent)
    {
        return 0;
    }
    int weight = 1;
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i].first == parent)
            continue;
        int temp = WeightTree(tree[now][i].first, now);
        if (now == 1)
        {
            printf("1's temp: %d\n", temp);
            printf("1's weight before: %d\n", weight + temp);
        }
        weight += temp;
        result += weight * tree[now][i].second;
        result %= MOD;
        if (temp)
        {
            weight -= temp;
            weight += temp * tree[now][i].second;
        }
        weight += tree[now][i].second;
        if (now == 1)
        {
            printf("1's weight after: %d\n", weight);
        }
    }
    printf("%d's result: %d\n", now, result);
    return (weight - 1) % MOD;
}
int main()
{
    int n;
    scanf("%d", &n);
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        tree[x].push_back({y, w});
        tree[y].push_back({x, w});
    }
    WeightTree(1, 0);
    printf("%d", result);
}