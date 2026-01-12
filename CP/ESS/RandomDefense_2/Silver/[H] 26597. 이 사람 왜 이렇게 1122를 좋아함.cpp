#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long int q, upper = -1000000000000000000, lower = 1000000000000000000;
    char c;
    int flag = 0, res = 0, fflag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %1c%*c", &q, &c);
        if (c == '^')
        {
            upper = max(upper, q + 1);
        }
        else
            lower = min(lower, q - 1);
        if (!flag)
        {
            if (upper > lower)
            {
                flag = i + 1;
            }
        }
        if (lower == upper && !fflag)
        {
            res = i + 1;
            fflag = 1;
        }
    }
    if (!flag)
    {
        if (fflag)
            printf("I got it!\n%d", res);
        else
            printf("Hmm...");
    }
    else if (flag)
        printf("Paradox!\n%d", flag);
    return 0;
}