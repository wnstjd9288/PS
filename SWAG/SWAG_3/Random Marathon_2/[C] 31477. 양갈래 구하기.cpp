#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> m[100001];
int visited[100001];
int dfs(int n, int weight)
{
    visited[n] = 1;
    if (m[n].size() == 1 && n != 1)
        return m[n][0].second;
    int total = 0;
    for (int i = 0; i < m[n].size(); i++)
    {
        if (!visited[m[n][i].first])
            total += dfs(m[n][i].first, m[n][i].second);
    }
    if (n == 1)
        return total;
    else
        return total < weight ? total : weight;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        m[a].push_back(make_pair(b, w));
        m[b].push_back(make_pair(a, w));
    }
    printf("%d", dfs(1, 0));
    return 0;
}