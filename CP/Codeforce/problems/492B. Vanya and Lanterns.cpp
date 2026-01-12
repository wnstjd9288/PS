#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, m;
    unsigned int arr[1002];
    double res = -1;
    double k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n - 1; i++)
    {
        res = res > arr[i + 1] - arr[i] ? res : arr[i + 1] - arr[i];
    }
    k = arr[0] > m - arr[n - 1] ? arr[0] : m - arr[n - 1];
    k = k > res / 2 ? k : res / 2;
    printf("%.9lf", k);
    return 0;
}