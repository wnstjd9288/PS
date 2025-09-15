    #include <bits/stdc++.h>
    int map[1000001] = {
        0,
    };
    long long int d[1001] = {
        0,
    };
    int main()
    {
        int n, m;
        long long int result = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            map[i] = (a + map[i - 1]) % m;
            d[map[i]]++;
        }
        result += d[0];
        for (int i = 0; i < m; i++)
        {
            if (d[i])
            {
                result += d[i] * (d[i] - 1) / 2;
            }
        }
        printf("%lld", result);
    }