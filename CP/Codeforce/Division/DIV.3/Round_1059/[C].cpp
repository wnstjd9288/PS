#include <bits/stdc++.h>

int binary(int *arr, int a)
{
    int cnt = -1;
    while (a)
    {
        cnt++;
        arr[cnt] = a % 2;
        a /= 2;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        int stra[50] = {
            0,
        },
            strb[50] = {
                0,
            };
        int res[50];
        int result = 0;
        scanf("%d%d", &a, &b);
        int alen = binary(stra, a);
        int blen = binary(strb, b);
        if (alen < blen)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i <= alen; i++)
        {
            if (strb[i])
            {
                res[i] = stra[i] ? 0 : 1;
            }
            else
                res[i] = stra[i] ? 1 : 0;
            if (res[i])
                result += pow(2, i);
        }
        if (result == 0)
            printf("0\n");
        else if (result > a)
        {
            printf("2\n");
            printf("%d %d\n", result - (int)pow(2, alen), (int)pow(2, alen));
        }
        else
            printf("1\n%d\n", result);
    }
}