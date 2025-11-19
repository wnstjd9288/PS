#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int x, y;
} cod;
typedef struct
{
    cod a, b;
} line;
bool cmp1(const line a, const line b)
{
    return a.a.y < b.b.y;
}
bool cmp2(const line a, const line b)
{
    return a.a.x < b.b.x;
}
vector<int> time;
int main()
{
    int n, t;
    cod start, now;
    int dir = 0; // 0,1,2,3 => wasd;
    line l[501];
    vector<line> cross[501];
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        cod temp;
        scanf("%d%d%d%d", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
        if (!i)
            start = {l[i].a.x, l[i].a.y};
        if (l[i].a.x == l[i].b.x)
        {
            if (!i)
                dir = 0;
            if (l[i].a.y > l[i].b.y)
            {
                if (!i)
                    dir = 2;
                temp = l[i].a;
                l[i].a = l[i].b;
                l[i].b = temp;
            }
        }
        if (l[i].a.y == l[i].b.y)
        {
            if (!i)
                dir = 3;
            if (l[i].a.x > l[i].b.x)
            {
                if (!i)
                    dir = 1;
                temp = l[i].a;
                l[i].a = l[i].b;
                l[i].b = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (l[i].a.x == l[i].b.x && l[j].a.y == l[j].b.y) // i=|, j=ㅡ
                if (l[j].a.x <= l[i].a.x && l[i].a.x <= l[j].b.x && l[i].a.y <= l[j].a.y && l[j].a.y <= l[i].b.y)
                    cross[i].push_back(l[j]);
            if (l[i].a.y == l[i].b.y && l[j].a.x == l[j].b.x) // i=ㅡ, j=|
                if (l[j].a.y <= l[i].a.y && l[i].a.y <= l[j].b.y && l[i].a.x <= l[j].a.x && l[j].a.x <= l[i].b.x)
                    cross[i].push_back(l[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cross[i].empty())
            continue;
        if (l[i].a.x == l[i].b.x)
            sort(cross[i].begin(), cross[i].end(), cmp1);
        else
            sort(cross[i].begin(), cross[i].end(), cmp2);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nline: {%d,%d}-{%d,%d}\n", l[i].a.x, l[i].a.y, l[i].b.x, l[i].b.y);
        for (int j = 0; j < cross[i].size(); j++)
        {
            printf("{%d,%d}-{%d,%d}\n", cross[i][j].a.x, cross[i][j].a.y, cross[i][j].b.x, cross[i][j].b.y);
        }
    }
    printf("%d", dir);
    // dir == 0,3 순방향 || dir == 1,2 역방향
    while ()
}