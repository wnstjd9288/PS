#include <stdio.h>

int main()
{
    int a, b, c, b_prime;
    int sum = 0;
    scanf("%d %d %d", &a, &b, &c);
    sum = a;
    b_prime = b;
    while (b_prime != 0)
    {
        sum *= 10;
        b_prime /= 10;
    }
    sum += b;
    printf("%d\n%d", a + b - c, sum - c);
    return 0;
}