#include <bits/stdc++.h>
char s[1001];
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    if (s[len - 1] == '0')
    {
        int cnt = 0;
        for (int i = 0; i < len; i++)
            cnt += s[i] - '0';
        if (cnt != len - 1)
            for (int i = 0; i < len; i++)
            {
                printf("1");
            }
        else
        {
            s[len - 2] = '0';
            printf("%s", s);
        }
    }
    else
    {
        printf("%s", s);
    }
    return 0;
}