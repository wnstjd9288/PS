#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, now;
    double a, b, c, d;
    scanf("%d %d", &n, &now);
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double good, bad;
    if (now)
    {
        good = c;
        bad = d;
    }
    else
    {
        good = a;
        bad = b;
    }
    for (int i = 1; i < n; i++)
    {
        double next_good = good * a + bad * c;
        double next_bad = good * b + bad * d;
        good = next_good;
        bad = next_bad;
    }
    printf("%.0lf\n%.0lf",good*1000,bad*1000);
}