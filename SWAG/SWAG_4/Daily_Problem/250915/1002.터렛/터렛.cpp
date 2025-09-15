#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int arr[6] = {
            0,
        };
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (arr[0] == arr[3] && arr[1] == arr[4] && arr[2] == arr[5])
            printf("-1\n");
        else
        {
            int d = (arr[0] - arr[3]) * (arr[0] - arr[3]) + (arr[1] - arr[4]) * (arr[1] - arr[4]); //(두 중점간의 거리)^2
            if (d == (arr[2] + arr[5]) * (arr[2] + arr[5]) || d == (arr[2] - arr[5]) * (arr[2] - arr[5]))
                printf("1\n");
            else if ((arr[2] - arr[5]) * (arr[2] - arr[5]) < d && d < (arr[2] + arr[5]) * (arr[2] + arr[5]))

                printf("2\n");
            else
                printf("0\n");
        }
    }
}