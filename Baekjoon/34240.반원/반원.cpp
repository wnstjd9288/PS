#include <bits/stdc++.h>
using namespace std;

struct cod
{
    long double x;
    long double y;
};

cod c[100001];
long double fix_zero(long double x)
{
    const long double EPS = 1e-12;
    long double r = roundl(x);

    if (fabsl(x - r) < EPS)
        return r;

    return x;
}

long double dis(cod a, cod b)
{
    return fix_zero(sqrtl(powl(a.x - b.x, 2) + powl(a.y - b.y, 2)));
}

int main()
{
    int n;
    cod a, b;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%Lf %Lf", &c[i].x, &c[i].y);
    }
    scanf("%Lf %Lf %Lf %Lf", &a.x, &a.y, &b.x, &b.y);
    long double result = 0;
    long double r = dis(a, b);
    long double dx = b.x - a.x;
    long double dy = b.y - a.y;

    long double theta = atan2(dy, dx);
    long double phi = M_PI / 2 - theta;
    long double cs = cos(phi);
    long double sn = sin(phi);

    auto rotate = [&](cod p)
    {
        long double x = p.x - a.x;
        long double y = p.y - a.y;
        return cod{
            fix_zero(x * cs - y * sn),
            fix_zero(x * sn + y * cs)};
    };

    cod A2 = rotate(a); // (0,0)
    cod B2 = rotate(b); // now B2 ≈ (0, r)
    for (int i = 0; i < n; i++)
        c[i] = rotate(c[i]);

    for (int i = 0; i < n; i++)
    {
        if (c[i].x > 0)
        {
            if (-r <= c[i].y && c[i].y <= r)
                result += c[i].x;
            else if (c[i].y < -r)
                result += dis(c[i], {0, -r});
            else if (c[i].y > r)
                result += dis(c[i], {0, r});
        }
        else if (fabsl(c[i].x) < 1e-12)
        {
            if (-r <= c[i].y && c[i].y <= r)
                result += 0;
            else if (c[i].y < -r)
                result += dis(c[i], {0, -r});
            else if (c[i].y > r)
                result += dis(c[i], {0, r});
        }
        else
        {
            if (dis(c[i], {0, 0}) > r)
                result += dis(c[i], {0, 0}) - r;
        }
    }
    printf("%.10Lf", result);
    return 0;
}
