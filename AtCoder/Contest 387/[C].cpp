#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll result[19][10];
ll mul(int n, int index)
{
    ll m = 1;
    for (int i = 0; i <= index; i++)
        m *= n;
    return m;
}
int digit(ll x, int *arr)
{
    int cnt = 0;
    while (x != 0)
    {
        arr[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    return cnt;
}
int num(ll x)
{
    int prev = -1;
    while (x != 0)
    {
        prev = x % 10;
        x /= 10;
    }
    return prev;
}
int main()
{
    ll l, r;
    bool flag1 = false;
    int la[19], ra[19];
    scanf("%lld%lld", &l, &r);
    l--;
    for (int i = 0; i < 18; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            result[i][j] += mul(j, i) + result[i][j - 1];
            // if (i < 3)
            //     printf("%lld ", result[i][j]);
        }
        // if (i < 3)
        //     puts("");
        result[i + 1][0] = result[i][9];
    }
    int ld = digit(l, la) - 2, rd = digit(r, ra) - 2;
    int ln = num(l), rn = num(r);
    bool flag = false;
    for (int i = ld; i >= 0; i--)
    {
        if (la[i] >= ln)
        {
            flag = true;
            flag1 = true;
        }
        if (flag)
            la[i] = ln - 1;
    }
    flag = false;
    for (int i = rd; i >= 0; i--)
    {
        if (ra[i] >= rn)
        {
            flag = true;
        }
        if (flag)
            ra[i] = rn - 1;
    }
    l = 0, r = 0;
    ll a = 1;
    for (int i = 0; i < ld + 2; i++)
    {
        l += la[i] * a;
        a *= 10;
    }
    a = 1;
    for (int i = 0; i < rd + 2; i++)
    {
        r += ra[i] * a;
        a *= 10;
    }
    // printf("l,r %lld %lld\n", l, r);
    // printf("ln,rn %lld %lld\n", ln, rn);
    // printf("ld,rd %lld %lld\n", ld, rd);
    ll res1 = result[ld][ln - 1], res2 = result[rd][rn - 1];
    // printf("%lld %lld\n", res1, res2);
    flag = false;
    a = 1;
    while (l >= 10)
    {
        int k = (l % 10);
        if (!flag)
        {
            k++;
            flag = true;
        }
        res1 += a * k;
        l /= 10;
        a *= ln;
    }
    ll b = 1;
    flag = false;
    while (r >= 10)
    {
        int k = (r % 10);
        if (!flag)
        {
            k++;
            flag = true;
        }
        res2 += b * k;
        r /= 10;
        b *= rn;
        // printf("res2: %lld\n", res2);
    }
    // printf("%lld %lld\n", res1, res2);
    printf("%lld", res2 - res1);
}