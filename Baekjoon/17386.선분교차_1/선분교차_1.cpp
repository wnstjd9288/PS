#include <bits/stdc++.h>
using namespace std;
long long int CCW(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3)
{
    if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) < 0)
        return -1;
    else if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) == 0)
        return 0;
    else
        return 1;
}
int main()
{
    long long int a[4], b[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &b[i]);
    }
    if (CCW(a[0], a[1], a[2], a[3], b[0], b[1]) * CCW(a[0], a[1], a[2], a[3], b[2], b[3]) <= 0 && CCW(b[0], b[1], b[2], b[3], a[0], a[1]) * CCW(b[0], b[1], b[2], b[3], a[2], a[3]) <= 0)
        printf("1");
    else
        printf("0");
    return 0;
}