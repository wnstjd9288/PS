#include <bits/stdc++.h>
using namespace std;
long long int res = 0;
long long int tri[100001], p[100001], A[100001];
long long int maximum[100001];
void Solve(int n, long long int price, bool flag)
{
    if (n == -1)
        return;
    if (tri[n])
        return;
    if (flag)
    {
        tri[n] = 1;
        res++;
        Solve(p[n], price, flag);
        return;
    }
    if (p[n] != -1)
    {
        if (tri[p[n]])
            return;
        if (maximum[p[n]])
        {
            if (maximum[p[n]] <= A[p[n]])
            {
                if (maximum[p[n]] + price > A[p[n]])
                {
                    if (price < maximum[p[n]] + A[p[n]])
                    {
                        Solve(p[n], price, true);
                        return;
                    }
                }
            }
            else
            {
                if (A[p[n]] + price > maximum[p[n]])
                {
                    if (price < maximum[p[n]] + A[p[n]])
                    {
                        Solve(p[n], price, true);
                        return;
                    }
                }
            }
            if (abs(A[p[n]] - maximum[p[n]]) > abs(A[p[n]] - price))
                maximum[p[n]] = price;
        }
        else
        {
            maximum[p[n]] = price;
        }
        Solve(p[n], price, false);
    }
}
int main()
{
    int n, a, b;
    scanf("%d%d", &n, &a);
    p[1] = -1;
    A[1] = a;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        p[i] = a;
        A[i] = b;
        Solve(i, A[i], false);
        printf("%lld\n", res);
    }

    return 0;
}

/*

5
10
1 2
2 2
3 2
4 2

*/