#include <bits/stdc++.h>
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    double a = n, b = m, c;
    double res = 1;
    for (int i = 1; i <= k; i++)
    {
        res *= (a - m) / a;
        printf("%lf\n", (double)(1 - res));
        a -= 1;
    }
    return 0;
}
