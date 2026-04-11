#include <bits/stdc++.h>
using namespace std;
struct cod
{
    int x;
    int y;
};
int main()
{
    cod a, b;
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);
    int dx = abs(a.x - b.x), dy = abs(a.y - b.y);
    if ((dx + dy) % 2)
    {
        printf("-1");
        return 0;
    }
    if (!(dx % 2))
        printf("%d %d", (a.x + b.x) / 2, (a.y + b.y) / 2);
    else
    {
        if (a.x > b.x)
        {
            cod temp = a;
            a = b;
            b = temp;
        }
        if (a.y <= b.y)
            printf("%d %d", (a.x + b.x + 1) / 2, (a.y + b.y - 1) / 2);
        else
            printf("%d %d", (a.x + b.x - 1) / 2, (a.y + b.y - 1) / 2);
        }
}