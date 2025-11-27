#include <bits/stdc++.h>
using namespace std;
long long int arr[200001];
long long int res = 0;
int main()
{
    int n, s, e;
    long long int k;
    scanf("%d %d %d", &n, &s, &e);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    scanf("%lld", &k);
    if (abs(s - e) >= k)
    {
        printf("0");
        return 0;
    }
    if (s > e)
    {
        int temp = s;
        s = e;
        e = temp;
    }
    for (int i = s; i >= 1; i--)
    {
        res += arr[i];
        if (arr[i] == 1)
            break;
    }
    for (int i = s + 1; i < e; i++)
        res += arr[i];
    for (int i = e; i <= n; i++)
    {
        res += arr[i];
        if (arr[i] == 1)
            break;
    }
    printf("%d", res >= k ? 1 : 0);
    return 0;
}