#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int visited[1001] = {0};
int n, m;

void BFS()
{
    int queue[1001], h = -1, t = -1;
    for (int i = 0; i < 1001; i++)
    {
        visited[i] = 0;
    }
    queue[++t] = 1;
    visited[1] = 1;
    while (h != t)
    {
        int now = queue[++h];
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (!visited[next])
            {
                visited[next] = visited[now] + 1;
                queue[++t] = next;
            }
        }
    }
}

int main()
{
    int q;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        BFS();
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", visited[j] - 1);
        }
        puts("");
    }
    return 0;
}