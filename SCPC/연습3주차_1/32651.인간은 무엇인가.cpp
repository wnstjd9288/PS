#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 100000 && !(n % 2024))
        printf("Yes");
    else
        printf("No");
}