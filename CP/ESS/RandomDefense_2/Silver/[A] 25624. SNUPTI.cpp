#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int flag = 0;
    set<string> s_SNUPTI;
    long long int res = 1;
    char s[20001][26], SNUPTI[26][26];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            SNUPTI[i][j] = 0;
        }
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", s[i]);
        if (s_SNUPTI.count(string(s[i])))
            flag = 1;
        else
            s_SNUPTI.insert(string(s[i]));
        for (int j = 0; j < n; j++)
        {
            SNUPTI[j][s[i][j] - 65] = 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cnt += SNUPTI[j][i];
        }
        if (cnt >= 2)
        {
            flag = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 26; j++)
        {
            cnt += SNUPTI[i][j];
        }
        res *= cnt;
    }
    if (res != m)
        flag = 1;
    if (flag)
        printf("NO");
    else
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (SNUPTI[i][j])
                    printf("%c", j + 65);
            }
            puts("");
        }
    }
    return 0;
}