#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main()
{
    scanf("%d%d%d", &x, &y, &z);
    while (1)
    {
        if (x == y * z)
        {
            printf("Yes");
            return 0;
        }
        else if (x < y * z)
            break;
        x++;
        y++;
    }
    printf("No");
}