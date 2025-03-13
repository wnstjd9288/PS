#include <stdio.h>
#include <string.h>
char s[1000001], t[100001];
int main()
{
    int alpha[26] = {
        0,
    };
    int flag = 0;
    scanf("%s", s);
    scanf("%s", t);
    int tlen = strlen(t), slen = strlen(s);

    for (int i = 0; i < strlen(t); i++)
        alpha[t[i] - 97]++;
    for (int i = 0; i < strlen(s); i++)
        if (!alpha[s[i] - 97])
        {
            flag = 1;
            break;
        }
    if (slen == 1 && !flag)
        flag = 2;
    if (tlen == 1 && !flag)
        flag = 3;
    if (!flag)
    {
        int start = 0, end;
        int pointer = 0;

        while (1)
        {
            if (t[start] == s[pointer])
                break;
            start++;
        }
        end = start + 1;
        pointer++;
        while (pointer != slen)
        {
            if (t[end % tlen] == s[pointer])
                pointer++;
            end++;
        }
        int result;
        result = end / tlen + 1;
        if (!(end % tlen))
            result--;
        printf("%d", result);
    }
    else
    {
        if (flag == 2)
            printf("1");
        else if (flag == 3)
            printf("%d", slen);
        else
            printf("-1");
    }
    return 0;
}