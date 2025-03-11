#include <stdio.h>

int main()
{
    int max = -1;
    int index = -1;
    for (int i = 0; i < 9; i++)
    {
        int n;
        scanf("%d", &n);
        if (n > max)
        {
            max = n;
            index = i + 1;
        }
    }
    printf("%d\n%d", max, index);
    return 0;
}