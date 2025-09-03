#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long>> m[5001];
long long visited[5001] = {
    0,
};
void dfs(int n, int prev)
{
    for (int i = 0; i < m[n].size(); i++)
    {
        if (prev != m[n][i].first)
        {
            if (!visited[m[n][i].first] || visited[m[n][i].first] < visited[n] + m[n][i].second)
            {
                visited[m[n][i].first] = visited[n] + m[n][i].second;
                dfs(m[n][i].first, n);
            }
        }
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        m[a].push_back(make_pair(b, c));
        m[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d point : ", i);
        for (int j = 0; j < m[i].size(); j++)
            printf("%d ", m[i][j].first);
        puts("");
    }
    dfs(1, -1);
    long long res = -1;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, visited[i]);
    }
    printf("%d", res);
}