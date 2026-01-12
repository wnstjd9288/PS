#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[200001];
ll d[200001];
ll dmul[11];
unordered_map<ll, ll> table[11];
ll digit(ll x)
{
    int cnt = 0;
    while (x != 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}
int main()
{
    ll n, m;
    ll k = 1;
    ll result = 0;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        d[i] = digit(arr[i]);
        arr[i] %= m;
    }
    for (int i = 0; i <= 10; i++)
    {
        dmul[i] = k % m;
        k *= 10;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            table[j][(dmul[j] * arr[i]) % m]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        result += table[d[i]][(m - arr[i]) % m];
    }
    printf("%lld", result);
}