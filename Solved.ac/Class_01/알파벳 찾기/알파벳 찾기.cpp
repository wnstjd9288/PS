#include <stdio.h>

int main()
{
    int a[27];
    char s[101];
    scanf("%s", s);
    for (int i = 0; i < 27; i++)
        a[i] = -1;
    for (int i = 0;; i++)
    {
        if (s[i] == '\0')
            break;
        if (a[s[i] - 97] == -1)
            a[s[i] - 97] = i;
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", a[i]);
    return 0;
}