#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    int arr[5] = {
        0,
    };
    int res = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (1 <= b && b <= 2)
            arr[0]++;
        else if (3 <= b && b <= 4)
        {
            if (a)
                arr[1]++;
            else
                arr[2]++;
        }
        else
        {
            if (a)
                arr[3]++;
            else
                arr[4]++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        res += arr[i] / k;
        if (arr[i] % k)
            res++;
    }
    printf("%d", res);
}