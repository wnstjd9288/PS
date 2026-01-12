#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
int weight[1001];
int max_w[1001];
int result = -1;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &weight[i]);
        max_w[i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int u = 1; u <= n; u++)
    {
        for (int w : graph[u])
        {
            for (int v : graph[w])
            {
                if (v == u)
                    continue;

                if (max_w[v])
                {
                    int other = max_w[v];
                    result = max(result, weight[u] + weight[v] + weight[w] + weight[other]);
                    if (weight[w] > weight[other])
                        max_w[v] = w;
                }
                else
                    max_w[v] = w;
            }
        }
        for (int w : graph[u])
        {
            for (int v : graph[w])
            {
                max_w[v] = 0;
            }
        }
    }
    printf("%d", result);
    return 0;
}