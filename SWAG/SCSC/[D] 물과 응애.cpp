#include <bits/stdc++.h>
char s[500001];
int sum[500001] = {
    0,
};
int water(int n)
{
    if (n % 3 == 0)
    {
        if (s[0] == 'O' || s[n - 1] == 'O')
            return 0;
        int cnt_o = 0;
        sum[0] = 1;
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1];
            if (s[i] == 'H')
                sum[i]++;
            else
            {
                cnt_o++;
                if (sum[i] < cnt_o)
                    return 0;
            }
        }
        for (int i = 0; i < n; i++)
            sum[i] = 0;
        cnt_o = 0;
        sum[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            sum[i] = sum[i + 1];
            if (s[i] == 'H')
                sum[i]++;
            else
            {
                cnt_o++;
                if (sum[i] < cnt_o)
                    return 0;
            }
        }
        if (cnt_o != n / 3)
            return 0;
    }
    else
        return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    if (water(n))
        printf("pure");
    else
        printf("mix");
}