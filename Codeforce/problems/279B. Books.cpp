#include <stdio.h>
int n, m;
int arr[100001];
int sum[100001] = {
    0,
};
int max = -1;
void two_pointer(int start, int end)
{
    if (start == end && arr[end] > m)
        return;
    if (sum[start] - sum[end] <= m)
    {
        max = max > end - start ? max : end - start;
        return;
    }

    if (sum[start] - sum[start + 1] > sum[end - 1] - sum[end])
    {
        two_pointer(start + 1, end);
    }
    else if (sum[start] - sum[start + 1] == sum[end - 1] - sum[end])
    {
        two_pointer(start + 1, end);
        two_pointer(start, end - 1);
    }
    else
    {
        two_pointer(start, end - 1);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum[i] = arr[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        sum[i - 1] += sum[i];
    }
    two_pointer(0, n);
    printf("%d", max);
    return 0;
}