#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int C[2222][2222] = {
    0,
};
long long int H(long long int a, long long int b)
{
    if (!a || !b)
        return 1;
    return C[a + b - 1][a];
}
int main()
{
    long long int cnt = 1, res = 0;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for (int i = 0; i < 2200; i++)
    {
        C[i][0] = C[i][i] = 1;
    }
    for (int i = 2; i < 2200; i++)
    {
        for (int j = 1; j < i; j++)
        {
            C[i][j] = (C[i - 1][j - 1] % p + C[i - 1][j] % p) % p;
        }
    }
    for (int i = 0; i <= k; i += 2)
    {
        long long int a = H(k - i, n) % p;
        long long int b = H(i / 2, m) % p;
        if (!n && k - i != 0)
            a = 0;
        if (!m && i / 2 != 0)
            b = 0;
        cnt = (a * b) % p;
        res = ((res % p) + (cnt % p)) % p;
    }
    printf("%lld", res);
}