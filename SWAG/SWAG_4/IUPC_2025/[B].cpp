#include <bits/stdc++.h>

int main()
{
    int n, m;
    int k;
    char s[3001];
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    for (int i = 0; i < k; i++)
    {
        switch (s[i])
        {
        case 'A':
            if (n <= 2)
                n += 2;
            else
                n -= 2;
            break;
        case 'B':
            if (n == 1)
                n = 2;
            else if (n == 2)
                n = 1;
            else if (n == 3)
                n = 4;
            else
                n = 3;
            m = m % 2 + 1;
            break;
        case 'C':
            if (n == 1)
                n = 4;
            else if (n == 2)
                n = 3;
            else if (n == 3)
                n = 2;
            else
                n = 1;
            m = m % 2 + 1;
            break;
        case 'D':
            if (m == 1)
            {
                if (n != 1)
                    n--;
                else
                    m++;
            }
            else
            {
                if (n != 4)
                    n++;
                else
                    m--;
            }
            break;
        default:
            break;
        }
    }
    printf("%d %d", n, m);
    return 0;
}