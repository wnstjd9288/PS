#include <stdio.h>
#include <string.h>
int main()
{
    int flag = 0;
    char s[1000];
    gets(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            flag = 1;
            puts("");
            continue;
        }
        printf("%c", s[i]);
    }
    if (!flag)
        printf("\n-");
}