#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        char s[21];
        scanf("%d %s", &n, s);
        for (int j = 0;; j++)
        {
            if (s[j] == '\0')
                break;
            for (int k = 0; k < n; k++)
                printf("%c", s[j]);
        }
        puts("");
    }
    return 0;
}