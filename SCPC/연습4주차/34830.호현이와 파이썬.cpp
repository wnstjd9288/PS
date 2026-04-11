#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int res = n + n * (n - 3) / 2;
    if (!(n % 2))
        res += n / 2 - 1;
    printf("%lld",res);
}