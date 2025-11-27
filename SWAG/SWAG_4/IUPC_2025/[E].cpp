#include <bits/stdc++.h>
typedef struct grid
{
    int x, y;
} cod;
int n;
cod xy[8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int score[5][5];
int knight[5][5];
int res = -1;

void DFS(cod now, int s)
{
    if (now.x == n)
    {
        res = res > s ? res : s;
        return;
    }
    bool flag = true;
    for (int i = 0; i < 8; i++)
    {
        cod next = {now.x + xy[i].x, now.y + xy[i].y};
        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n)
            continue;
        if (knight[next.x][next.y])
        {
            flag = false;
            break;
        }
    }
    cod next = {now.x + (now.y + 1) / n, (now.y + 1) % n};
    DFS(next, s);
    if (flag)
    {
        knight[now.x][now.y] = 1;
        DFS(next, s + score[now.x][now.y]);
        knight[now.x][now.y] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &score[i][j]);
        }
    DFS({0, 0}, 0);
    printf("%d", res);
    return 0;
}