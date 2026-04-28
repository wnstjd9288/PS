#include <bits/stdc++.h>
typedef long long int ll;
ll res = 0;
ll cnt = 1;
void binary(ll n)
{
    if (n == 0)
        return;
    res += (n % 2) * (powl(2, cnt++) - 1);
    binary(n / 2);
}
int main()
{
    ll n;
    scanf("%lld", &n);
    binary(n);
    printf("%lld", res);
}