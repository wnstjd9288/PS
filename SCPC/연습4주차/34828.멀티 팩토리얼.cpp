#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
long long int n, p;
long long int fact(long long int s, long long int e, long long int q)
{
    if (s == e)
        return s;
    long long int mid = s + (q / 2) * p;
    if (q % 2)
    {
        return ((fact(s, mid - p, q / 2) % mod * fact(mid + p, e, q / 2) % mod) % mod * mid % mod) % mod;
    }
    return (fact(s, mid - p, q / 2) % mod * fact(mid, e, q / 2) % mod) % mod;
}
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%lld%lld", &n, &p);
        long long int q, r;
        q = n / p + 1;
        r = n % p;
        if (!r)
        {
            q--;
            r = p;
        }
        printf("%lld\n", fact(r, n, q) % mod);
    }
}