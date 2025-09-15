#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    int s = 0, e = 1, sum = 1, cnt = 0;
    while (s != e || e <= n)
    {
        if (sum == n)
        {
            cnt++;
            e++;
            sum += e;
        }
        else if (sum < n)
        {
            e++;
            sum += e;
        }
        else
        {
            sum -= s;
            s++;
        }
    }
    printf("%d", cnt);
}