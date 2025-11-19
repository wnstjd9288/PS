#include <bits/stdc++.h>
int arr[10000001];
bool is_pel(int x)
{
    char s[10001];
    int cnt = 0;
    while (x)
    {
        s[cnt++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < cnt; i++)
        if (s[i] != s[cnt - i - 1])
            return false;
    return true;
}
int main()
{
    arr[1] = 1;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (!arr[i])
            for (int j = i * i; j <= 10000000; j += i)
                arr[j] = 1;
    }
    int n;
    scanf("%d", &n);
    for (int i = n; i < 10000000; i++)
    {
        if (!arr[i] && is_pel(i))
        {
            printf("%d\n", i);
            return 0;
        }
    }
}