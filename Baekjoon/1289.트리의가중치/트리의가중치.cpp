#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
<<<<<<< HEAD
vector<vector<pair<int, int>>> tree;
int result = 0;
int WeightTree(int now, int parent)
=======
vector<vector<pair<long long int, long long int>>> tree;
long long int result = 0;
long long int WeightTree(int now, int parent)
>>>>>>> b9d668b67d880f07cd494917552ad562bfe9b72a
{
    if (tree[now].size() == 1 && tree[now][0].first == parent)
    {
        return 0;
    }
<<<<<<< HEAD
    int weight = 1;
=======
    long long int weight = 0;
>>>>>>> b9d668b67d880f07cd494917552ad562bfe9b72a
    for (int i = 0; i < tree[now].size(); i++)
    {
        if (tree[now][i].first == parent)
            continue;
<<<<<<< HEAD
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
=======
        long long int temp = WeightTree(tree[now][i].first, now) % MOD;
        result = (result % MOD + (((weight + 1) % MOD * (temp + 1) % MOD) % MOD * tree[now][i].second % MOD) % MOD) % MOD;
        weight = (weight % MOD + ((temp + 1) % MOD * tree[now][i].second % MOD) % MOD) % MOD;
    }
    return weight % MOD;
>>>>>>> b9d668b67d880f07cd494917552ad562bfe9b72a
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
<<<<<<< HEAD
    printf("%d", result);
=======
    printf("%lld", result);
>>>>>>> b9d668b67d880f07cd494917552ad562bfe9b72a
}