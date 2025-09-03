#include <bits/stdc++.h>
using namespace std;
vector<int> m[250001];
int tree[250001] = {
    0,
};
long long cnt[250001] = {
    0,
};
int parent[250001] = {
    0,
};
void mk_tree(int now)
{
    int que[250001];
    int visited[250001] = {
        0,
    };
    int h = -1, t = -1;
    que[++t] = now;
    tree[now] = now;
    while (h != t)
    {
        now = que[++h];
        visited[now] = 1;
        for (int i = 0; i < m[now].size(); i++)
        {
            int next = m[now][i];
            if (visited[next])
                continue;
            tree[next] = now;
            que[++t] = next;
        }
    }
}
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void union_find(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return;

    cnt[pa] += cnt[pb];
    parent[pb] = pa;
}
int main()
{
    int n, q, k, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    mk_tree(1);
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        vector<int> l;
        long long res = 0;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &a);
            l.push_back(a);
            parent[a] = a;
            cnt[a] = 1;
        }

        for (int j = 0; j < k; j++)
        {
            if (parent[tree[l[j]]])
            {
                union_find(tree[l[j]], l[j]);
            }
        }
        for (int j = 0; j < k; j++)
        {
            if (find(l[j]) == l[j])
            {
                res += cnt[l[j]] * (cnt[l[j]] - 1) / 2;
            }
            cnt[l[j]] = 1;
            parent[l[j]] = 0;
        }
        printf("%lld\n", res);
    }
}