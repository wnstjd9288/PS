#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int arr[10][4] = {
            0,
        };
        int res[10] = {
            0,
        };
        int tri[2001][2001] = {
            0,
        };
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%1d", &tri[i][j]);
                // 0123=>상하좌우
                arr[tri[i][j]][0] = arr[tri[i][j]][0] ? min(arr[tri[i][j]][0], i) : i;
                arr[tri[i][j]][1] = max(arr[tri[i][j]][1], i);
                arr[tri[i][j]][2] = arr[tri[i][j]][2] ? min(arr[tri[i][j]][2], j) : j;
                arr[tri[i][j]][3] = max(arr[tri[i][j]][3], j);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int height = max(i - 1, n - i);
                int width = max(j - 1, n - j);
                if (arr[tri[i][j]][0])
                    res[tri[i][j]] = max(res[tri[i][j]], width * abs(i - arr[tri[i][j]][0]));
                if (arr[tri[i][j]][1])
                    res[tri[i][j]] = max(res[tri[i][j]], width * abs(i - arr[tri[i][j]][1]));
                if (arr[tri[i][j]][2])
                    res[tri[i][j]] = max(res[tri[i][j]], height * abs(j - arr[tri[i][j]][2]));
                if (arr[tri[i][j]][3])
                    res[tri[i][j]] = max(res[tri[i][j]], height * abs(j - arr[tri[i][j]][3]));
            }
        }
        for (int i = 0; i <= 9; i++)
        {
            printf("%d ", res[i]);
        }
        puts("");
    }
    return 0;
}