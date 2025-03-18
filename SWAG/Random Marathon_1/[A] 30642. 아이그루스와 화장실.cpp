#include <stdio.h>

int main()
{
    int n, m;
    char s[100];
    scanf("%d", &n);
    scanf("%*c%s", s);
    scanf("%d", &m);
    switch (s[0])
    {
    case 'a':
        if (m % 2)
            printf("%d", m);
        else
        {
            if (m == n)
                printf("%d", m - 1);
            else
                printf("%d", m + 1);
        }
        break;
    case 'i':
        if (m % 2 == 0) 
            printf("%d", m);
        else
        {
            if (m == n)
                printf("%d", m - 1);
            else
                printf("%d", m + 1);
        }
        break;
    default:
        break;
    }
}