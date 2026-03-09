#include <bits/stdc++.h>
using namespace std;
long long int s[1000001];
int main()
{
    long long int n, m, a, d, cnt = 0, maxcnt = 0;
    scanf("%lld %lld %lld %lld", &n, &a, &d, &m);
    for (int i = 1; i < n; i++)
    {
        cnt += i;
    }
    maxcnt = cnt;
    for (long long int i = n; i >= 1; i--)
    {
        long long int k = a * i;
        if ((m - k) % d == 0)
        {
            long long int dn = (m - k) / d;
            if (cnt <= dn && dn <= maxcnt)
            {
                long long int sum = 0;
                for (int j = 0; j < i; j++)
                {
                    s[j] = j + (dn - cnt) / i;
                    sum += j + (dn - cnt) / i;
                }
                while (sum < dn)
                {
                    for (int j = i - 1; j >= 0 && sum < dn; j--)
                    {
                        s[j]++;
                        sum++;
                    }
                }
                printf("%lld\n", i);
                for (int j = 0; j < i; j++)
                {
                    printf("%lld ", s[j] * d + a);
                }
                return 0;
            }
        }
        cnt -= i - 1;
        maxcnt -= n - i;
    }
    printf("-1");
    return 0;
}