#include <bits/stdc++.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", (m / n) % 2 ? n - m % n : m % n);
    return 0;
}