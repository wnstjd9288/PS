#include <bits/stdc++.h>
using namespace std;
char s[101];
bool flag = false;
int main()
{
    int n, x = 0, y = 0;
    unordered_map<char, bool> m;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
        m[s[i]] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] - s[i] > 0)
            x++;
        else
            y++;
    }
    if (abs(x - y) <= 1)
    {
        printf("%d\n%s", n, s);
        return 0;
    }
    if (x > y)
    {
        int cnt = 0;
        char last = s[n - 1];
        for (int i = last; i >= 'A'; i--)
        {
            if (!m[i])
                cnt++;
        }
        if (cnt >= x - y - 1)
        {
            int c = 0;
            for (int i = last; i >= 'A'; i--)
            {
                if (!m[i])
                {
                    s[n++] = i;
                    c++;
                    if (c == x - y - 1)
                        break;
                }
            }
        }
        else
        {
            int c = 0;
            for (int i = 'Z'; i >= 'A'; i--)
            {

                if (!m[i])
                {
                    s[n++] = i;
                    c++;
                    if (c == x - y + 1)
                        break;
                }
            }
        }
    }
    else
    {
        int cnt = 0;
        char last = s[n - 1];
        for (int i = last; i <= 'Z'; i++)
        {
            if (!m[i])
                cnt++;
        }
        if (cnt >= y - x - 1)
        {
            int c = 0;
            for (int i = last; i <= 'Z'; i++)
            {
                if (!m[i])
                {
                    s[n++] = i;
                    c++;
                    if (c == y - x - 1)
                        break;
                }
            }
        }
        else
        {
            int c = 0;
            for (int i = 'A'; i <= 'Z'; i++)
            {

                if (!m[i])
                {
                    s[n++] = i;
                    c++;
                    if (c == y - x + 1)
                        break;
                }
            }
        }
    }
    printf("%d\n%s", n, s);
}