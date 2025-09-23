#include <bits/stdc++.h>

char s[1000001];
int main()
{
    int n, m, cnt = 0;
    int req[4];
    int pw[4] = {
        0,
    };
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i < 4; i++)
        scanf("%d", &req[i]);
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'A':
            pw[0]++;
            break;
        case 'C':
            pw[1]++;
            break;
        case 'G':
            pw[2]++;
            break;
        case 'T':
            pw[3]++;
            break;
        }
        if (i >= m)
        {
            switch (s[i - m])
            {
            case 'A':
                pw[0]--;
                break;
            case 'C':
                pw[1]--;
                break;
            case 'G':
                pw[2]--;
                break;
            case 'T':
                pw[3]--;
                break;
            }
        }
        if (i >= m - 1)
        {
            bool flag = true;
            for (int j = 0; j < 4; j++)
            {
                if (req[j] > pw[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cnt++;
        }
    }
    printf("%d", cnt);
}