#include <bits/stdc++.h>

int main()
{
    int n, a, b, i;
    scanf("%d%d%d", &n, &a, &b);
    for (i = 0; a != b; i++)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }
    printf("%d", i);
}