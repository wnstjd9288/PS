#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    long long int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long int lcm(long long int a, long long int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n, a;
    long long int b;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (!i)
            b = a;
        else
        {
            b = lcm(a, b);
        }
    }
    printf("%lld", b*2);
}