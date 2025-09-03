#include <bits/stdc++.h>
using namespace std;
map<long long int, int> um;
int m;
void odd(long long int now, int n, int start)
{
    if (n == 0)
    {
        long long int cpy = now / 10;
        while (cpy)
        {
            now = now * 10 + cpy % 10;
            cpy /= 10;
        }
        um[now % m]++;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (n == start && !i)
            continue;
        odd(now * 10 + i, n - 1, start);
    }
}
void even(long long int now, int n, int start)
{
    if (n == 0)
    {
        long long int cpy = now;
        while (cpy)
        {
            now = now * 10 + cpy % 10;
            cpy /= 10;
        }
        um[now % m]++;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (n == start && !i)
            continue;
        even(now * 10 + i, n - 1, start);
    }
}
int main()
{
    int n;
    long long int mul = 1;
    scanf("%d %d", &n, &m);
    int a = n / 2;
    for (int i = 0; i < a; i++)
    {
        mul *= 10;
    }
    printf("%lld\n", mul);
    mul %= m;
    if (a % 2)
    {
        if (a == 1)
            for (int i = 1; i <= 9; i++)
                um[i]++;
        else
            odd(0, a / 2 + 1, a / 2 + 1);
    }
    else
        even(0, a / 2, a / 2);
    long long int cnt = 0;
    map<int, int> check;
    for (auto p : um)
    {
        printf("%lld %d\n", p.first, p.second);
        if (um.count((m - (p.first * mul) % m) % m))
        {
            printf("in: %lld %d\n", p.first, p.second);
            cnt += p.second * um[(m - (p.first * mul) % m) % m];
        }
    }
    printf("%lld", cnt);
}