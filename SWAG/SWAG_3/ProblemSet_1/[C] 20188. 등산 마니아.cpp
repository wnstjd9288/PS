#include <bits/stdc++.h>
using namespace std;
vector<int> a[300001];
long long visited[300001] = {
    0,
};
void dfs(int now)
{
    if (visited[now])
        return;
    visited[now] = 1;
    for (int i = 0; i < a[now].size(); i++)
    {
        if (visited[a[now][i]])
            continue;
        dfs(a[now][i]);
        visited[now] += visited[a[now][i]];
    }
    return;
}
int main()
{
    long long n, cnt = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);

    for (int i = 2; i <= n; i++)
    {
        cnt += n * (n - 1) / 2 - (n - visited[i]) * (n - visited[i] - 1) / 2;
    }
    printf("%lld", cnt);
    return 0;
}