#include <stdio.h>
#include <stdlib.h>

int arr[500001] = {
    0,
};
int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y)
        return 1;
    else if (x == y)
        return 0;
    else
        return -1;
}

int lo_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (arr[mid] < k)
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
        if (arr[mid] <= k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

int main()
{
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &m);
    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        printf("%d ", up_bound(x, 0, n) - lo_bound(x, 0, n));
    }
    return 0;
}