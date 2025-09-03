#include <bits/stdc++.h>
int main()
{
    int n, c;
    int w, h;
    scanf("%d %d", &n, &c);
    w = h = n;
    for (int i = 0; i < c; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= h || y >= w)
            continue;
        if (x * w >= y * h)
            h = x;
        else
            w = y;
    }
    printf("%d", w * h);
    return 0;
}