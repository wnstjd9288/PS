#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[500011];
ll res = 0;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        scanf("%lld", &arr[i]);
    res = arr[0] % 1000000007;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1 || res == 1 && i == 1)
        {
            res = (res % 1000000007 + arr[i] % 1000000007) % 1000000007;
        }
        else
            res = (res % 1000000007 * arr[i] % 1000000007) % 1000000007;
    }
    printf("%lld", res);
    return 0;
}