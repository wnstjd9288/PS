#include <bits/stdc++.h>
using namespace std;
map<long long int, bool> m;
int main()
{
    int n;
    long long int now = 0;
    scanf("%d", &n);
    m[0]=true;
    for (int i = 1; i <= n; i++)
    {
        if (now - i < 0 || m[now - i])
            now += i;
        else
            now -= i;
        m[now] = true;
    }
    printf("%lld", now);
}