#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
} Coo;
int cmp(const void *a, const void *b)
{
    Coo x = *(Coo *)a;
    Coo y = *(Coo *)b;

    if (x.x > y.x)
        return 1;
    else if (x.x == y.x)
    {
        if (x.y > y.y)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}

int n, a, b;
Coo map[500001];
int lo_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (map[mid].x < k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int up_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (map[mid].x <= k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int find_square(Coo now, int index)
{
    int stack = 0;
    int x[3] = {1, 0, 1}, y[3] = {0, 1, 1};
    for (int i = 0; i < 3; i++)
    {
        Coo next;
        next.x = now.x + x[i] * a;
        next.y = now.y + y[i] * b;
        int start = lo_bound(next.x, index, n);
        int end = up_bound(next.x, index, n);
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (map[mid].y < next.y)
                start = mid + 1;
            else
                end = mid;
        }
        if (map[end].x == next.x && map[end].y == next.y)
            stack++;
        else
            break;
    }
    if (stack == 3)
        return 1;
    else
        return 0;
}
int main()
{
    int cnt = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &map[i].x, &map[i].y);
    }
    qsort(map, n, sizeof(Coo), cmp);
    for (int i = 0; i < n; i++)
    {
        cnt += find_square(map[i], i);
    }
    printf("%d", cnt);
    return 0;
}