#include <bits/stdc++.h>
using namespace std;
long long int hit(long long int h, long long int s)
{
    if (h <= 2)
        return 1;
    if (h <= 4)
        return 2 + s;

    long long int result = (h+s*3+1)/2;
    return result;
}
int main()
{
    long long int h, s;
    scanf("%lld%lld", &h, &s);
    long long int res = hit(h, s);
    printf("%lld", res);
}