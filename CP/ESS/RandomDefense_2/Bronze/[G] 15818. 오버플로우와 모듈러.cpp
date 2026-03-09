#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    long long int res = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        res = ((res % m) * (a % m)) % m;
    }
    printf("%lld", res);
    return 0;
}