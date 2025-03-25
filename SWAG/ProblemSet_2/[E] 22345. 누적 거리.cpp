#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> loc;
bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
ll lo_bound(ll s, ll e, ll k)
{
    ll mid;
    while (s < e)
    {
        mid = (s + e) / 2;
        if (loc[mid] < k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int main()
{
    ll n, q;
    ll x, a;
    vector<pair<ll, ll>> village;
    scanf("%lld %lld", &n, &q);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld %lld", &a, &x);
        loc.push_back(x);
        village.push_back(make_pair(a, x));
    }
    sort(loc.begin(), loc.end());
    sort(village.begin(), village.end(), compare);
    village[0].second *= village[0].first;

    for (ll i = 1; i < n; i++)
    {
        village[i].second = village[i - 1].second + village[i].first * village[i].second;
        village[i].first += village[i - 1].first;
    }

    // for (int i = 0; i < n; i++)
    //     printf("%lld ", loc[i]);
    for (ll i = 0; i < q; i++)
    {
        scanf("%lld", &x);
        ll k = lo_bound(0, n, x);
        printf("k: %lld\n", k);
        ll res = 0;
        if (k - 1 >= 0)
        {
            res = x * (2 * village[k - 1].first - village[n - 1].first) - (2 * village[k - 1].second - village[n - 1].second);
        }
        else
        {
            res = x * (-1) * (village[n - 1].first) + (village[n - 1].second);
        }
        printf("%lld\n", res);
    }

    return 0;
}