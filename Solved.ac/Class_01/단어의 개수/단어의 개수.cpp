#include <stdio.h>

int main()
{
    char s[1000001];
    int cnt = 1;
    gets(s);
    for (int i = 0;; i++)
    {
        if (s[i] == '\0')
        {
            if (s[i - 1] == ' ')
                cnt--;
            break;
        }

        if (s[i] == ' ' && i != 0)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}