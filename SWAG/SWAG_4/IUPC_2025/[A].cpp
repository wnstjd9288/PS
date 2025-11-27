#include <bits/stdc++.h>

int main()
{
    int n, m;
    int res;
    scanf("%d %d", &n, &m);
    if (n == m)
    {
        res = 1 + (n - 2) * (n - 2);
    }
    else
    {
        n--;
        m--;
        res = n > m ? m * m : n * n;
    }
    printf("%d", res);
    return 0;
}