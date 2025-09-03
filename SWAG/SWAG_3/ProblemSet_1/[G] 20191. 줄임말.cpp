#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char text;
    int index;
} Text;

char s[1000001], t[100001];
Text T[100001];

int cmp(const void *a, const void *b)
{
    Text x = *(Text *)a;
    Text y = *(Text *)b;
    if (x.text > y.text)
        return 1;
    else if (x.text == y.text)
        return x.index - y.index;
    else
        return -1;
}
int find(int start_point, int end, char c)
{
    // printf("\n startpoint : %d", start_point);
    int start = 0;
    int mid;
    if (start_point >= end)
        return -1;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (T[mid].text < c)
        {
            start = mid + 1;
        }
        else if (T[mid].text == c)
        {
            // printf("\nin circle, mid : %d", mid);
            if (T[mid].index < start_point)
            {
                if (T[mid + 1].text != c)
                    return -1;
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        else
        {
            end = mid;
        }
        // printf("\n%d %d %c", start, end, T[start].text);
    }
    return T[start].index;
}

int main()
{
    int alpha[26] = {
        0,
    };
    int flag = 0;
    scanf("%s", s);
    scanf("%s", t);
    int tlen = strlen(t), slen = strlen(s);

    for (int i = 0; i < tlen; i++)
    {
        alpha[t[i] - 97]++;
        T[i].text = t[i];
        T[i].index = i;
    }
    qsort(T, tlen, sizeof(Text), cmp);
    /*for (int i = 0; i < tlen; i++)
    {
        if (i && T[i].text != T[i - 1].text)
            puts("");
        printf("%c,%d ", T[i].text, T[i].index);
    }*/
    for (int i = 0; i < slen; i++)
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
        int start = 0, end = tlen;
        int pointer = 0;
        int cnt = 1;
        while (pointer != slen)
        {
            int res = find(start, end, s[pointer]);
            // printf("\nres : %d", res);
            if (res != -1)
            {
                start = res + 1;
                pointer++;
            }
            else
            {
                start = 0;
                cnt++;
            }
        }
        printf("%d", cnt);
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