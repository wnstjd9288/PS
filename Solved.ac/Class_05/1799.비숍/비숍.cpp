#include <bits/stdc++.h>

int map[11][11] = {
    0,
};
int max = 0;
int n;
void mkBishop(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        int gap = abs(y - i);
        if (!gap)
            continue;
        if (y > i)
        {
            if (x - gap >= 0 && y - gap >= 0)
            {
                if (map[x - gap][y - gap] > 2)
                    map[x - gap][y - gap]++;
                if (map[x - gap][y - gap] == 1)
                    map[x - gap][y - gap] = 3;
            }
            if (x + gap < n && y - gap >= 0)
            {
                if (map[x + gap][y - gap] > 2)
                    map[x + gap][y - gap]++;
                if (map[x + gap][y - gap] == 1)
                    map[x + gap][y - gap] = 3;
            }
        }
        else
        {
            if (x - gap >= 0 && y + gap < n)
            {
                if (map[x - gap][y + gap] > 2)
                    map[x - gap][y + gap]++;
                if (map[x - gap][y + gap] == 1)
                    map[x - gap][y + gap] = 3;
            }

            if (x + gap < n && y + gap < n)
            {
                if (map[x + gap][y + gap] > 2)
                    map[x + gap][y + gap]++;
                if (map[x + gap][y + gap] == 1)
                    map[x + gap][y + gap] = 3;
            }
        }
    }
}
void rmBishop(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        int gap = abs(y - i);
        if (!gap)
            continue;
        if (y > i)
        {
            if (x - gap >= 0 && y - gap >= 0)
            {
                if (map[x - gap][y - gap] == 3)
                    map[x - gap][y - gap] = 1;
                else if (map[x - gap][y - gap] > 2)
                    map[x - gap][y - gap]--;
            }
            if (x + gap < n && y - gap >= 0)
            {
                if (map[x + gap][y - gap] == 3)
                    map[x + gap][y - gap] = 1;
                else if (map[x + gap][y - gap] > 2)
                    map[x + gap][y - gap]--;
            }
        }
        else
        {
            if (x - gap >= 0 && y + gap < n)
            {
                if (map[x - gap][y + gap] == 3)
                    map[x - gap][y + gap] = 1;
                else if (map[x - gap][y + gap] > 2)
                    map[x - gap][y + gap]--;
            }
            if (x + gap < n && y + gap < n)
            {
                if (map[x + gap][y + gap] == 3)
                    map[x + gap][y + gap] = 1;
                else if (map[x + gap][y + gap] > 2)
                    map[x + gap][y + gap]--;
            }
        }
    }
}
void chess(int color, int num, int x, int y)
{
    if (num > max)
        max = num;
    for (int i = 0; i < n; i++)
    {
        for (int j = (i + color) % 2; j < n; j += 2)
        {
            if (i == 0 && j == (i + color) % 2)
            {
                i = x;
                j = y;
            }
            if (map[i][j] == 1)
            {
                map[i][j] = -1;
                mkBishop(i, j);
                chess(color, num + 1, i, j);
            }
        }
    }
    if (map[x][y] == -1)
    {
        map[x][y] = 1;
        rmBishop(x, y);
    }
    return;
}
int main()
{
    int res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    chess(0, 0, 0, 0);
    res += max;
    max = 0;
    chess(1, 0, 0, 1);
    printf("%d", res + max);
    return 0;
}