#include <bits/stdc++.h>
using namespace std;
char s[10000001];
int main()
{
    int now = -1;
    scanf("%[^\n]s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            if (now == -1)
                now == -1;
            else
                now = 0;
            continue;
        }
        if ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9' || s[i] == '$' || s[i] == '?' || s[i] == '+' || s[i] == '_')
        {
            if (now != 1 && now != -1)
            {
                printf(" ");
            }
            now = 1;
        }
        else if (s[i] == '&' || s[i] == '|')
        {
            if (now != 2 && now != -1)
            {
                printf(" ");
                now = 2;
            }
            else
            {
                if (now == -1)
                    now = 2;
                else
                    now = 3;
            }
        }
        else
        {
            if (now != -1)
                printf(" ");
            now = 4;
        }
        printf("%c", s[i]);
    }
    return 0;
}