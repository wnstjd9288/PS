#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll x, y, p, a, b;
    scanf("%lld%lld%lld%lld%lld", &x, &y, &p, &a, &b);
    ll res = 0;
    p += (y - 1) * b;
    for (int i = 0; i < x; i++)
    {
        res += p;
        p -= a;
    }
    printf("%lld", res);
    return 0;
}