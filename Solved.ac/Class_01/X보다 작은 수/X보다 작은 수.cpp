#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a < m)
            printf("%d ", a);
    }
    return 0;
}