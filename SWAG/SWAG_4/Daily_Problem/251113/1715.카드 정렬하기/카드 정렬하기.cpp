#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
int main()
{
    int n;
    long long int res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        pq.push(a);
    }
    while (pq.size() != 1)
    {
        long long int a = pq.top();
        pq.pop();
        long long int b = pq.top();
        pq.pop();
        pq.push(a + b);
        res += a + b;
    }
    printf("%lld", res);
}