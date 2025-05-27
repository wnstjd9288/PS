#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, a, b;
    int water[101] = {
        0,
    };
    scanf("%d%d%d%d", &n, &k, &a, &b);
    int flag = 0;
    for (int i = 0; i < n; i++)
        water[i] = k;

    for (int day = 1; !flag; day++)
    {
        int m = 99999999;
        for (int i = 0; i <= n - a; i++)
        {
            int sum = 0;
            for (int j = i; j < i + a; j++)
            {
                sum += water[j];
            }
            m = min(m, sum);
        }
        for (int i = 0; i <= n - a; i++)
        {
            int sum = 0;
            for (int j = i; j < i + a; j++)
            {
                sum += water[j];
            }
            if (sum == m)
            {
                for (int j = i; j < i + a; j++)
                {
                    water[j] += b;
                }
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            water[i]--;
            if (!water[i])
            {
                printf("%d", day);
                flag = 1;
                break;
            }
        }
    }

    return 0;
}