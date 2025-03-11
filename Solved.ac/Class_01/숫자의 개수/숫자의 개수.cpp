#include <stdio.h>

int main()
{
    int num[10] = {
        0,
    };
    int a, b, c;
    int x;
    scanf("%d %d %d", &a, &b, &c);
    x = a * b * c;
    while (x != 0)
    {
        num[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n", num[i]);
    return 0;
}