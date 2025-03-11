#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    m -= 45;
    if (m < 0)
    {
        m += 60;
        n--;
        if (n < 0)
            n += 24;
    }
    printf("%d %d", n, m);
    return 0;
}