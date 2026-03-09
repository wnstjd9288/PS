#include <stdio.h>

int main()
{
    int n, m;
    int arr[100001];
    int sum = 0, cnt = 0;
    int res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (1)
        {
            if (sum <= m)
                break;
            sum -= arr[cnt++];
        }
        res = res > i - cnt + 1 ? res : i - cnt + 1;
    }
    printf("%d", res);
    return 0;
}