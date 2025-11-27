#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> arr[91]; // 0,1
int main()
{
    int n;
    scanf("%d", &n);
    arr[1] = {0, 1};
    for (int i = 2; i <= n; i++)
    {
        arr[i] = {arr[i - 1].first + arr[i - 1].second, arr[i - 1].first};
    }
    printf("%lld", arr[n].first + arr[n].second);
}
