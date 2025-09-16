#include <bits/stdc++.h>
using namespace std;
int tree[3001] = {
    0,
};
int result[3001] = {
    0,
};
int point[3001][4];
int CCW(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3)
{
    if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) < 0)
        return -1;
    else if (((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) == 0)
        return 0;
    else
        return 1;
}
int parent(int x)
{
    if (tree[x] == x)
        return x;
    else
        return parent(tree[x]);
}
void Union_Find(int x, int y)
{
    tree[parent(y)] = parent(x);
}
int main()
{
    int n, m = -1, cnt = 0;
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
            {
                if (CCW(point[i][0], point[i][1], point[i][2], point[i][3], point[j][0], point[j][1]) * CCW(point[i][0], point[i][1], point[i][2], point[i][3], point[j][2], point[j][3]) == 0 && CCW(point[j][0], point[j][1], point[j][2], point[j][3], point[i][0], point[i][1]) * CCW(point[j][0], point[j][1], point[j][2], point[j][3], point[i][2], point[i][3]) == 0)
                {
                    // 한 선 위에 네 점이 있는경우.
                    if (point[i][0] == point[i][2] && point[i][0] == point[j][0] && point[i][0] == point[j][2])
                    {
                        if (max(point[i][1], point[i][3]) >= min(point[j][1], point[j][3]) && max(point[j][1], point[j][3]) >= min(point[i][1], point[i][3]))
                            Union_Find(i, j);
                    }
                    else
                    {
                        if (max(point[i][0], point[i][2]) >= min(point[j][0], point[j][2]) && max(point[j][0], point[j][2]) >= min(point[i][0], point[i][2]))
                            Union_Find(i, j);
                    }
                }
                else
                    Union_Find(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        result[parent(tree[i])]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (result[i] > 0)
            cnt++;
        m = max(result[i], m);
    }
    printf("%d\n%d", cnt, m);
    return 0;
}