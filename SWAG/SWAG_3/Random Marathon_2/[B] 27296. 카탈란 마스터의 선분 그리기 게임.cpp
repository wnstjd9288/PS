#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long n;

        scanf("%lld", &n);
        if (n <= 1)
            printf("1 0\n");
        else
            printf("0 1\n");
    }
}