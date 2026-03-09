#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n;
        bool flag = true;
        char s1[21], s2[21];
        char alpha[26] = {
            0,
        };
        scanf("%d", &n);
        scanf("%s %s", s1, s2);
        for (int i = 0; i < n; i++)
        {
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i])
                flag = false;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}