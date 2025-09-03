#include <bits/stdc++.h>

int main()
{
    int n, m;
    long long int a = 1, b = 1;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n - 1; i++)
    {
        a = a * 10 + 1;
    }
    for (int i = 0; i < m - 1; i++)
    {
        b = b * 10 + 1;
    }
    printf("%lld", a + b);
}