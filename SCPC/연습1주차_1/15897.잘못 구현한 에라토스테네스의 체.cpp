#include <bits/stdc++.h>
long long int arr[40000];
bool is_x(long long int n)
{
    for (int i = 1; i <= 31622; i++)
    {
        if (i * i == n)
            return true;
    }
    return false;
}
int main()
{
    long long int n;
    long long int res = 0;
    long long int check = 0;
    scanf("%lld", &n);
    res += n;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = (n - 1) / i;
        res += arr[i];
        if (i >= arr[i])
        {
            if (i > arr[i])
                res -= arr[i];
            check = i;
            break;
        }
    }
    for (int i = 2; i <= check; i++)
    {
        res += (arr[i - 1] - arr[i]) * (i - 1);
    }
    printf("%lld", res);
}