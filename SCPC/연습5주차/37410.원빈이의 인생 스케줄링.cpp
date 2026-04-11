#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[200001];
vector<int> t;
int main()
{
    int n;
    ll h = 0, k = 0, s = 0;
    scanf("%d", &n);
    t.resize(n);
    for (int i = 0; i < n; i++)
    {
        ll a;
        scanf("%d%lld", &t[i], &a);
        arr[t[i]] = max(arr[t[i]], a);
    }
    sort(t.begin(), t.end());
    for (int i = 1; i <= t[n - 1]; i++)
    {
        arr[i] = max(arr[i - 1], arr[i]);
    }
    for (int i = t[n - 1]; i >= 1; i--)
    {
        if (arr[i] > arr[i - 1])
            arr[i - 1] = arr[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[t[i]] > t[i])
        {
            printf("-1");
            return 0;
        }
        s += t[i] - arr[t[i]];
    }
    printf("%lld",s);
}