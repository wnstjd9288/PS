#include <bits/stdc++.h>
using namespace std;
long long int m[500001];
long long int result = 0;
int main()
{
    int n;
    long long int mod = 1000000007;
    scanf("%d", &n);
    m[0] = 0;
    for (int i = 1; i < n; i++)
    {
        long long int a;
        scanf("%lld", &a);
        m[i] = (((m[i - 1] % mod) * a) % mod + a) % mod;
        result = ((result % mod) + (m[i] % mod)) % mod;
    }
    printf("%lld", result);
    return 0;
}