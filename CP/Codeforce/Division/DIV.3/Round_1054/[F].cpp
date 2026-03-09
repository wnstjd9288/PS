#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tri(ll x)
{
    return x * (x + 1) / 2;
}
bool ok(ll m, ll h, ll d)
{
    ll s = m + 1;
    ll a = d / s;
    ll r = d % s;

    ll C = 0;

    C += (ll)r * tri(a + 1);
    C += (ll)(s - r) * tri(a);

    return C <= (ll)(h + m - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll h, d;
        scanf("%lld%lld", &h, &d);

        ll lo = 0, hi = d, ans = d;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid, h, d))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        printf("%lld\n", d + ans);
    }
}
