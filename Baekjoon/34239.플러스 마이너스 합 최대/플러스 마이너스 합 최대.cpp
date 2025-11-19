#include <bits/stdc++.h>
using namespace std;
long long int arr[200011];
long long int arr_ori[200011];
long long int res[200011][2]; // 0:Max 1:Min
int main()
{
    int n, maxi, mini;
    scanf("%d", &n);
    res[1][0] = -10000000000;
    res[1][1] = 10000000000;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        arr_ori[i] = arr[i];
        arr[i] = arr[i - 1] + (i % 2 ? 1 : -1) * arr[i];
        if (res[1][0] <= arr[i])
            maxi = i;
        if (res[1][1] >= arr[i])
            mini = i;
        res[1][0] = max(res[1][0], arr[i]);
        res[1][1] = min(res[1][1], arr[i]);
    }
    long long int m = res[1][0];
    for (int i = 2; i <= n; i++)
    {
        res[i][0] = -(res[i - 1][1] - arr_ori[i - 1]);
        res[i][1] = -(res[i - 1][0] - arr_ori[i - 1]);
        int temp = maxi;
        maxi = mini;
        mini = temp;
        if (maxi < i)
            continue;
        m = max(m, res[i][0]);
    }
    printf("%lld", m);
}