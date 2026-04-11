#include <bits/stdc++.h>
using namespace std;
int arr[5];
int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr[a]++;
    }
    sum += arr[4];
    sum += arr[3];
    arr[1] -= arr[3];
    sum += arr[2] / 2;
    if (arr[2] % 2)
    {
        sum++;
        arr[1] -= 2;
    }
    if (arr[1] > 0)
    {
        sum += arr[1] / 4;
        if (arr[1] % 4)
            sum++;
    }
    printf("%d", sum);
}