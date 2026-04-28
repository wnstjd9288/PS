#include <bits/stdc++.h>
typedef long long int ll;
ll res(ll n)
{
    ll s;
    ll max = 100000, min = 0, mid;
    ll val = 100000;
    ll prev = -1;
    printf("? 100000\n");
    fflush(stdout);
    scanf("%lld%*c", &s);
    if (s == 0)
        return 100000;
    for (int i = 0; i < 20; i++)
    {
        ll k;
        mid = (max + min) / 2;
        printf("? %lld\n", mid);
        fflush(stdout);
        scanf("%lld%*c", &k);
        if (k == 0)
            return mid;
        if (prev == mid)
            return max;
        // printf("%d %d %d %d / %d %d :: s, k, val, mid / min, max\n", s, k, val, mid, min, max);
        if (s - k == n * (val - mid))
        {
            max = mid;
            val = max;
            s = k;
            prev = mid;
            continue;
        }
        min = mid;
        prev = mid;
    }
    return max;
}
int main()
{
    ll n;
    scanf("%lld%*c", &n);
    printf("! %lld", res(n));
}