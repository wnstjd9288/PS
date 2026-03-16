#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
int main()
{
    int n, m;
    long long int res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        long long int a;
        scanf("%lld", &a);
        pq.push(a);
        res += a;
    }
    for (int i = 0; i < m; i++)
    {
        long long int a = pq.top();
        pq.pop();
        long long int b = pq.top();
        res += a + b;
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    printf("%lld", res);
}