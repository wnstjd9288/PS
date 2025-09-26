#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<vector<pair<long long int, long long int>>> tree;
long long int result = 0;
long long int WeightTree(int now, int parent)
{
    if (tree[now].size() == 1 && tree[now][0].first == parent)
    {
        return 0;
    }
    long long int weight = 0;
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i].first == parent)
            continue;
        long long int temp = WeightTree(tree[now][i].first, now) % MOD;
        result = (result % MOD + (((weight + 1) % MOD * (temp + 1) % MOD) % MOD * tree[now][i].second % MOD) % MOD) % MOD;
        weight = (weight % MOD + ((temp + 1) % MOD * tree[now][i].second % MOD) % MOD) % MOD;
    }
    return weight % MOD;
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
    printf("%lld", result);
}