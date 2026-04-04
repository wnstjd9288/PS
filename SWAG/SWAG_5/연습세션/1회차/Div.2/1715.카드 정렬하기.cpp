#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        pq.push(k);
    }
    long long int res = 0;
    while (pq.size() != 1)
    {
        long long int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        res += a + b;
    }
    printf("%lld", res);
}