#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (!a && !b && !c && !d)
            break;
        printf("%d %d\n", c - b, d - a);
    }
}