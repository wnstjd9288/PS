#include <bits/stdc++.h>

int main()
{
    int n, k = 0, flag = 0;
    scanf("%d", &n);
    int m = n;
    int cnt = 0;
    int start = 1;
    while (m > 0)
    {
        cnt++;
        m /= 10;
    }
    if (cnt > 1)
        start = n - 9 * cnt;
    if (start <= 0)
        start = 1;
    for (int i = start; i <= n; i++)
    {
        int j = i;
        k = 0;
        while (j > 0)
        {
            k += j % 10;
            j /= 10;
        }
        if (i + k == n)
        {
            flag = i;
            break;
        }
    }
    printf("%d", flag);
}