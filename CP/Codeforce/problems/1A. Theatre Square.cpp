#include <stdio.h>

int main()
{
    int n, m, a;
    long long int h, w;
    scanf("%d %d %d", &n, &m, &a);
    h = n / a;
    w = m / a;
    if (n % a)
        h++;
    if (m % a)
        w++;
    if (n == a && m == a)
    {
        h = w = 1;
    }
    printf("%lld", h * w);
    return 0;
}