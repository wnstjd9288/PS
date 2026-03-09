#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s1[101], s2[101];
    int c1 = -1, c2 = -1, flag = 0;
    scanf("%s%s", s1, s2);
    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u')
        {
            c1 = i;
        }
        if (c1 != -1)
        {
            if (!(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'))
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        printf("no such exercise");
        return 0;
    }
    else
    {
        flag = 0;
        for (int i = 0; i < strlen(s2); i++)
        {
            if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u')
            {
                c2 = i;
            }
            if (c2 != -1)
            {
                if (!(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u'))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            printf("no such exercise");
            return 0;
        }
        for (int i = 0; i <= c1; i++)
            printf("%c", s1[i]);
        for (int i = 0; i <= c2; i++)
            printf("%c", s2[i]);
    }
}