#include <stdio.h>

int main()
{
    int t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int cnt = 0, stack = 1;
        char s[81];
        scanf("%s", s);
        for (int j = 0;; j++)
        {
            if (s[j] == '\0')
                break;
            if (s[j] == 'O')
            {
                cnt += stack;
                stack++;
            }
            else
                stack = 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}