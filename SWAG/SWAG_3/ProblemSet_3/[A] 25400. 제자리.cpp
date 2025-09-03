#include <bits/stdc++.h>

int main()
{
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == cnt + 1)
            cnt++;
    }
    printf("%d", n - cnt);
}