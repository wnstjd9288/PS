#include <bits/stdc++.h>
using namespace std;
long long int arr[200001] = {
    0,
};
long long int arr_diff[200001] = {
    0,
};
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int n;
        long long int s = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            if (i)
            {
                arr_diff[i] = abs(arr[i] - arr[i - 1]);
                s += arr_diff[i];
            }
        }
        long long int res = s;
        for (int i = 0; i < n; i++)
        {
            if (!i)
            {
                res = min(res, s - arr_diff[1]);
            }
            else if (i == n - 1)
            {
                res = min(res, s - arr_diff[n - 1]);
            }
            else
            {
                res = min(res, s - (arr_diff[i] + arr_diff[i + 1] - abs(arr[i - 1] - arr[i + 1])));
            }
        }
        printf("%lld\n", res);
        for (int i = 0; i < n; i++)
            arr[i] = arr_diff[i] = 0;
    }
    return 0;
}