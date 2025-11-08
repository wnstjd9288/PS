#include <bits/stdc++.h>

int main()
{
    int n;
    int arr[200001] = {
        0,
    };
    long long cnt = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i])
            cnt++;
        else
            cnt--;
        sum += cnt;
    }
    printf("%lld", sum);
    return 0;
}