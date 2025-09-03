#include <bits/stdc++.h>
using namespace std;
long long a[5000] = {
    0,
};
long long res = 100000000000;
int resk = -1;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int k = 1; k <= n / 2; k++)
    {
        for (int i = 1; i <= n - 2 * k + 1; i++)
        {
            for (int j = i + k; j <= n - k + 1; j++)
            {
                if (res >= abs((a[i + k - 1] - a[i - 1]) - (a[j + k - 1] - a[j - 1])))
                {
                    res = abs((a[i + k - 1] - a[i - 1]) - (a[j + k - 1] - a[j - 1]));
                    resk = resk > k ? resk : k;
                }
            }
        }
    }
    printf("%d\n%lld", resk, res);
}