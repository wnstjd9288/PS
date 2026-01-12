#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr;
int main()
{
    long long int n, x, y, diff;
    long long int cnt = 0;
    bool flag = false;
    scanf("%lld %lld %lld", &n, &x, &y);
    diff = y - x;
    for (int i = 0; i < n; i++)
    {
        long long int a;
        scanf("%lld", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long long int val = arr[0] * y;
    cnt += arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] * y - val) % diff)
            break;
        else
        {
            cnt += arr[i] - (arr[i] * y - val) / diff;
            if (i == n - 1)
                flag = true;
        }
    }
    if (cnt == 0)
    {
        if (arr[0] * y < arr[n - 1] * x)
            cnt = -1;
    }
    printf("%lld", flag ? cnt : -1);
}