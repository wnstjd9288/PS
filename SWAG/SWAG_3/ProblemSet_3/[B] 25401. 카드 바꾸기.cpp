#include <bits/stdc++.h>
int check[2000001] = {
    0,
};
int list[501] = {
    0,
};
int main()
{
    int n;
    int res = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cnt = 0;
            int x = list[j] - list[i];
            if (x % (j - i))
                continue;
            x /= (j - i);
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (list[i] + (k - i) * x == list[k])
                    cnt++;
            }
            res = res > cnt ? res : cnt;
        }
    }
    printf("%d", n - res - 2);
}