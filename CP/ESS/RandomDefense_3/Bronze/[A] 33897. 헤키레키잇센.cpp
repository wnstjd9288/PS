#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int cnt = 1;
    int now = -1, start = 0;
    int m = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a < now)
        {
            m = max(m, i - start);
            start = i;
            cnt++;
        }
        now = a;
    }
    if (m == -1)
        m = n;
    else
    {
        m = max(n - start, m);
    }
    printf("%d %d", cnt, m);
}