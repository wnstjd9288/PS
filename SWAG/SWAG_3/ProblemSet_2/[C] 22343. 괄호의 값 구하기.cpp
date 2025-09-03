#include <bits/stdc++.h>
using namespace std;

char a[3000001], b[3000001];
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        bool flag = false;
        int x[3001] = {
            0,
        },
            y[3001] = {
                0,
            };
        int depth = 0;
        int maxa = -1, maxb = -1;
        scanf("%s", a);
        scanf("%s", b);
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == '(')
                depth++;
            else
            {
                depth--;
                if (a[i - 1] == '(')
                    x[depth]++;
            }
            maxa = maxa > depth ? maxa : depth;
        }
        for (int i = 0; i < strlen(b); i++)
        {
            if (b[i] == '(')
                depth++;
            else
            {
                depth--;
                if (b[i - 1] == '(')
                    y[depth]++;
            }
            maxb = maxb > depth ? maxb : depth;
        }
        int max = maxa > maxb ? maxa : maxb;
        for (int i = 0; i <= max; i++)
        {
            if (x[i] >= 2)
            {
                x[i + 1] += x[i] / 2;
                x[i] %= 2;
            }
            if (y[i] >= 2)
            {
                y[i + 1] += y[i] / 2;
                y[i] %= 2;
            }
        }
        for (int i = max + 1; i >= 0; i--)
        {
            if (x[i] != y[i])
            {
                flag = true;
                if (x[i] > y[i])
                    printf(">\n");
                else
                    printf("<\n");
                break;
            }
        }
        if (flag)
            continue;
        printf("=\n");
    }
    return 0;
}