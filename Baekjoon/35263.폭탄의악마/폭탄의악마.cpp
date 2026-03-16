#include <bits/stdc++.h>
int check[200001];
int arr[200001];
int prime_cnt[500001];
int prime_sum[500001];
double prob[500001];
int main()
{
    for (int i = 2; i <= 500000; i++)
    {
        if (prime_cnt[i])
            continue;
        for (int j = i; j <= 500000; j += i)
        {
            prime_cnt[j]++;
            prime_sum[j] += i;
        }
    }
    for (int i = 2; i <= 500000; i++)
    {
        prob[i] = (double)prime_sum[i] / prime_cnt[i];
    }
    int n, m;
    double result = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        check[a]++;
        check[b + 1]--;
    }

    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        now += check[i];
        if (now > 0)
            result += prob[arr[i - 1]];
        else
            result += arr[i - 1];
    }
    printf("%.10lf", result);
}