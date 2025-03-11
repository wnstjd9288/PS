#include <stdio.h>

int main()
{
    int a[42] = {
        0,
    };
    int n, cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n);
        a[n % 42] = 1;
    }
    for (int i = 0; i < 42; i++)
        if (a[i])
            cnt++;
    printf("%d", cnt);
    return 0;
}