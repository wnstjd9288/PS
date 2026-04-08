#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int ax, ay;
    long long int bx, by;
    long long int dx, dy;
    long long int x = 0, y = 0;
    scanf("%lld%lld", &ax, &ay);
    scanf("%lld%lld", &bx, &by);
    dx = abs(ax - bx);
    dy = abs(ay - by);
    int s = dx + dy;
    if (s % 2)
    {
        printf("-1");
        return 0;
    }
    s /= 2;
    x = min(ax, bx);
    y = max(ay, by);
    if (s > dx)
    {
        x = max(ax, bx);
        y -= s - dx;
    }
    else
        x += s;
    printf("%d %d",x,y);
}