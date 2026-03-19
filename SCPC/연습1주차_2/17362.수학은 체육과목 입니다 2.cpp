#include <bits/stdc++.h>
int arr[9] = {2, 1, 2, 3, 4, 5, 4, 3};
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", arr[n % 8]);
}