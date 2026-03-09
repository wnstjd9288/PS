#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
struct cmp
{
    bool operator()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) const
    {
        if (a.second == b.second)
            return a.first.second > b.first.second;
        return a.second > b.second;
    }
};
vector<vector<pair<int, int>>> graph;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
long long int visited[300001][2];
int n;
void BFS(int s, int e)
{
    visited[s][0] = 0;
    visited[s][1] = 0;
    for (int i = 0; i < graph[s].size(); i++)
    {
        visited[graph[s][i].first][0] = graph[s][i].second;
        visited[graph[s][i].first][1] = graph[s][i].second;
        pq.push({graph[s][i], graph[s][i].second});
    }
    while (!pq.empty())
    {
        pair<pair<int, int>, int> now = pq.top();
        pq.pop();
        for (int i = 0; i < graph[now.first.first].size(); i++)
        {
            if (visited[graph[now.first.first][i].first][0] == INF)
            {
                visited[graph[now.first.first][i].first][0] = visited[now.first.first][0] + graph[now.first.first][i].second + now.second;
                visited[graph[now.first.first][i].first][1] = graph[now.first.first][i].second + now.second;
                pq.push({graph[now.first.first][i], graph[now.first.first][i].second + now.second});
            }
            else if (visited[graph[now.first.first][i].first][0] > visited[now.first.first][0] + graph[now.first.first][i].second + now.second)
            {
                visited[graph[now.first.first][i].first][0] = visited[now.first.first][0] + graph[now.first.first][i].second + now.second;
                pq.push({graph[now.first.first][i], graph[now.first.first][i].second + now.second});
            }
            else if (visited[graph[now.first.first][i].first][0] == visited[now.first.first][0] + graph[now.first.first][i].second + now.second && visited[now.first.first][1] > graph[now.first.first][i].second + now.second)
            {
                visited[graph[now.first.first][i].first][0] = visited[now.first.first][0] + graph[now.first.first][i].second + now.second;
                pq.push({graph[now.first.first][i], graph[now.first.first][i].second + now.second});
            }
        }
    }
}
void print_binary(int num)
{
    if (!num)
        return;
    print_binary(num / 2);
    printf("%d", num % 2 ? 1 : 0);
}
int main()
{
    int m, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++)
        visited[i][0] = visited[i][1] = INF;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    BFS(s, e);
    print_binary(visited[e][0]);
    if(!visited[e][0])printf("0");
}