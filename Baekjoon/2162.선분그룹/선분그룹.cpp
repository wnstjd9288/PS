#include <bits/stdc++.h>
using namespace std;
int tree[3001];
int point[3001][4];
int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) < 0)
        return -1;
    else if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) == 0)
        return 0;
    else
        return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        tree[i] = i;
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &point[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (CCW(point[i][0], point[i][1], point[i][2], point[i][3], point[j][0], point[j][1]) * CCW(point[i][0], point[i][1], point[i][2], point[i][3], point[j][2], point[j][3]) <= 0 && CCW(point[j][0], point[j][1], point[j][2], point[j][3], point[i][0], point[i][1]) * CCW(point[j][0], point[j][1], point[j][2], point[j][3], point[i][2], point[i][3]) <= 0)
                Union_Find(i, j);
        }
    }
    return 0;
}