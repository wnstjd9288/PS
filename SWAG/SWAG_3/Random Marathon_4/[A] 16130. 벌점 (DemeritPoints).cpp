#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++)
    {
        char s[31];
        int point = 0;
        int de_point = 0;
        int cnt = 0;
        bool flag = true;
        scanf("%s", s);
        for (int j = 0; j < strlen(s); j++)
        {
            de_point = point / 10;
            if (s[j] >= 65)
                point += s[j] - 55;
            else
                point += s[j] - 48;
            if (de_point != point / 10 && point / 10 < 4)
                cnt += point / 10;
            if (point / 10 == 4)
            {
                printf("%d(weapon)\n", cnt);
                flag = false;
                break;
            }
            else if (point / 10 > 4)
            {
                printf("%d(09)\n", cnt);
                flag = false;
                break;
            }
        }
        if (flag)
            printf("%d\n", cnt);
    }
}