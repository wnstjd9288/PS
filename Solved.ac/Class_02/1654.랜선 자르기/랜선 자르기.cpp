#include <stdio.h>
int arr[10001], n, k;
long long cut(long long mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += arr[i] / mid;
    return cnt;
}
int main()
{
    long long high = -1, low = 1, mid;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        high = high > arr[i] ? high : arr[i];
    }
    while (high > low)
    {
        mid = (high + low) / 2;
        if (cut(mid) >= k && cut(mid + 1) < k)
            break;
        if (cut(mid) >= k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("%lld", (high + low) / 2);
    return 0;
}