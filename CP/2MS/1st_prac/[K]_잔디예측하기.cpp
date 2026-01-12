#include <bits/stdc++.h>
using namespace std;

char before[1001][1001];
char res[1001][1001];
queue<pair<int, int>> q;
int n, m, d;

void check(int x, int y)
{
    for (int i = x - d; i <= x + d; i++)
    {
        for (int j = y - d; j <= y + d; j++)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                continue;
            if (abs(i - x) + abs(j - y) > d)
                continue;
            if (res[i][j] == 'O' && before[i][j] == 'X')
            {
                before[i][j] = 'O';
                q.push({i, j});
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%*c");
        for (int j = 0; j < m; j++)
        {
            scanf("%1c", &before[i][j]);
        }
    }
    scanf("%d", &d);

    for (int i = 0; i < n; i++)
    {
        scanf("%*c");
        for (int j = 0; j < m; j++)
        {
            scanf("%1c", &res[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (before[i][j] == 'O')
                q.push({i, j});
        }
    }
    for (int i = 0; !q.empty(); i++)
    {
        pair<int, int> p = q.front();
        q.pop();
        check(p.first, p.second);
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (before[i][j] != res[i][j])
                flag = false;
        }
    }
    if (flag)
        printf("YES");
    else
        printf("NO");
}