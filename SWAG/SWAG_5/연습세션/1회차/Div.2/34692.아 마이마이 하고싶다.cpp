#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    int n, m;
    long long int k;
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 0; i < m; i++)
        pq.push(0);
    for (int i = 0; i < n; i++)
    {
        long long int time;
        scanf("%lld", &time);

        long long int now = pq.top();
        pq.pop();
        pq.push(now + time);
    }
    if (pq.top() <= k)
        printf("WAIT");
    else
        printf("GO");
}