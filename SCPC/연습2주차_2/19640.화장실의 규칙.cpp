#include <bits/stdc++.h>
using namespace std;
struct Compare
{
    bool operator()(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
    {
        if (a.first.first < b.first.first)
            return true;
        else if (a.first.first == b.first.first)
        {
            if (a.first.second < b.first.second)
                return true;
            else if (a.first.second == b.first.second)
            {
                return a.second.first % a.second.second > b.second.first % b.second.second;
            }
            else
                return false;
        }
        else
            return false;
    }
};
vector<pair<pair<int, int>, pair<int, int>>> arr;
priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, Compare> pq;
int line[100001];
int done[100001];
int main()
{
    int n, m, k;
    int cnt = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        arr.push_back({{a, b}, {i, m}});
    }
    for (int i = 0; i < m; i++)
    {
        if (i == n)
            break;
        pq.push(arr[i]);
    }
    while (1)
    {
        pair<pair<int, int>, pair<int, int>> now = pq.top();
        pq.pop();
        if (now.second.first == k)
        {
            printf("%d", cnt);
            break;
        }
        cnt++;
        line[now.second.first % m]++;
        if (line[now.second.first % m] * m + now.second.first % m >= n)
            done[now.second.first % m]++;
        if (done[now.second.first % m])
            continue;
        pq.push(arr[line[now.second.first % m] * m + now.second.first % m]);
    }
}