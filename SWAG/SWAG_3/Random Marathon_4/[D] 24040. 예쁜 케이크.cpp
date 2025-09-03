#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long n;
        scanf("%lld", &n);
        if (n % 9 == 0 || n % 3 == 2)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}