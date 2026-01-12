#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int max = -1;
        int arr[11] = {
            0,
        };
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] += arr[i - 1];
            for (int j = 0; j < i; j++)
            {
                max = max > (arr[i] - arr[j]) / (i - j) ? max : (arr[i] - arr[j]) / (i - j);
            }
        }
        printf("%d\n",max);
    }
}