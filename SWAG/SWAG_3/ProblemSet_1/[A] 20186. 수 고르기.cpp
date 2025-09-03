#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int arr[5001] = {
    0,
};

int main()
{
    int n, m;
    int sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < m; i++)
        sum += arr[i] - i;
    printf("%d", sum);
    return 0;
}