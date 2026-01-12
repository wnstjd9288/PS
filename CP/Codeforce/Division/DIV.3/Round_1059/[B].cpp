#include <bits/stdc++.h>
int visited[11];
int result[11];
char s[11];
bool flag = false;

bool is_pel(int n)
{
    int cnt = 0;
    char new_s[11];
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            new_s[cnt++] = s[i];
    }
    for (int i = 0; i < cnt; i++)
    {
        if (new_s[i] != new_s[cnt - i - 1])
            return false;
    }
    return true;
}
void search(int now, int prev, int n)
{
    if (flag)
        return;
    if (now >= n)
    {
        flag = is_pel(n);
        if (flag)
        {
            int res = 0;
            for (int i = 0; i < n; i++)
                res += visited[i];
            printf("%d\n", res);
            for (int i = 0; i < n; i++)
                if (visited[i])
                    printf("%d ", i + 1);
            puts("");
        }
        return;
    }

    search(now + 1, prev, n);
    if (s[now] >= s[prev])
    {
        visited[now] = 1;
        search(now + 1, now, n);
        visited[now] = 0;
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        flag = false;
        for (int i = 0; i < n; i++)
            visited[i] = result[i] = 0;
        search(0, 0, n);
        if (!flag)
            printf("-1\n");
    }
}