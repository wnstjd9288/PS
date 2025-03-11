#include <stdio.h>

int main()
{
    int n;
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        res += n * n;
    }
    printf("%d", res % 10);
    return 0;
}