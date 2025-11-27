#include <bits/stdc++.h>
char map[3][101];
int main()
{
    int n, j, s, h, k;
    int one = 0, two = 0;
    scanf("%d%d%d%d%d", &n, &j, &s, &h, &k);
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < n; i++)
        if (map[0][i] == 'v')
            s--;
    if (s < 0)
        h += s * k;
    for (int i = 0; i < n; i++)
    {
        if (map[2][i] == '^')
        {
            if (map[1][i] == '^')
                two++;
            else
                one++;
        }
    }
    j -= one;
    if (j > 0)
        j /= 2;
    j -= two;
    if (j < 0)
        h += j * k;
    printf("%d", h > 0 ? h : -1);
    return 0;
}