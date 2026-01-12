#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        int n, d, b, e;
        vector<int> num;
        vector<int> result;
        scanf("%d %d %d %d", &n, &d, &b, &e);
        int x = n, y = d;
        n %= d;
        for (int i = 0; i < 300; i++)
        {
            n *= 10;
            num.push_back(n / d);
            n %= d;
        }
        for (int j = 0; j < 260; j++)
        {
            num[299] *= 7;
            for (int i = 298; i >= 0; i--)
            {
                num[i] = num[i] * 7 + num[i + 1] / 10;
                num[i + 1] %= 10;
            }
            result.push_back(num[0] / 10);
            num[0] %= 10;
        }
        result[259]++;
        for (int i = 259; i >= 1; i--)
        {
            result[i - 1] += result[i] / 7;
            result[i] %= 7;
        }
        printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", t, x, y, b, e);
        for (int i = b; i <= e; i++)
            printf("%d", result[i]);
        puts("");
    }
    return 0;
}