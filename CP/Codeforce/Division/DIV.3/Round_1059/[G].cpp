#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        if (n == 2)
        {
            printf("-1\n");
            continue;
        }

        if (n == 3)
        {
            printf("1 3\n2 3\n");
            continue;
        }

        if (n == 4)
        {
            printf("1 2\n3 1\n4 1\n");
            continue;
        }

        printf("1 2\n2 3\n3 4\n1 %d\n", n);

        for (int i = 5; i < n; i++)
            printf("2 %d\n", i);
    }
}