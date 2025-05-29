#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    int arr[1002];
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int a, b, temp;
            long long int sum = 0;
            scanf("%d %d", &a, &b);
            for (int j = a; j <= b; j++)
            {
                sum += arr[j];
            }
            printf("%lld\n", sum);
            temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
        else
        {
            int a, b, c, d;
            long long int sum = 0;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            for (int j = a; j <= b; j++)
                sum += arr[j];
            for (int j = c; j <= d; j++)
                sum -= arr[j];
            printf("%lld\n", sum);
        }
    }
}