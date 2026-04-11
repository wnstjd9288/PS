#include <bits/stdc++.h>
typedef long long int ll;
ll arr[5];
ll x, y;
bool flag;
void meat(ll sum, int now)
{
    if (x <= sum && sum <= y)
    {
        printf("YES\n");
        flag = true;
        return;
    }
    if (now >= 5 || sum > y || flag)
        return;
    meat(sum + arr[now], now + 1);
    meat(sum, now + 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld", &x, &y);
        for (int i = 0; i < 5; i++)
        {
            scanf("%lld", &arr[i]);
        }
        flag = false;
        meat(0, 0);
        if (!flag)
            printf("NO\n");
    }
}