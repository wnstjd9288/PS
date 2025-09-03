#include <bits/stdc++.h>

int main()
{
    int n;
    int map[6] = {0, 0, 0, 0, 0, 0};
    int max[6] = {6, 11, 15, 18, 20, 0};
    int min[6] = {1, 3, 6, 10, 15, 0};
    long long int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            map[4]++;
        else if (i == 1)
        {
            map[4]--;
            map[3] += 2;
            map[1]++;
        }
        else
        {
            map[2]++;
            map[0] += 2;
        }
        for (int j = 0; j < 6; j++)
        {
            result += (min[j] + max[j]) * map[j];
        }
    }
    printf("%lld", result);
}