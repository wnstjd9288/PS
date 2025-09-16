#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[4], b[4];
    long long int change[2] = {
        0,
    };
    long long int s, e;
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &b[i]);
    }
    if (a[0] > a[2])
    {
        change[0] = a[0];
        change[1] = a[1];
        a[0] = a[2];
        a[1] = a[3];
        a[2] = change[0];
        a[3] = change[1];
    }
    else if (a[0] == a[2])
    {
        if (a[1] > a[3])
        {
            change[0] = a[1];
            a[1] = a[3];
            a[3] = change[0];
        }
    }
    if (b[0] > b[2])
    {
        change[0] = b[0];
        change[1] = b[1];
        b[0] = b[2];
        b[1] = b[3];
        b[2] = change[0];
        b[3] = change[1];
    }
    else if (b[0] == b[2])
    {
        if (b[1] > b[3])
        {
            change[0] = b[1];
            b[1] = b[3];
            b[3] = change[0];
        }
    }
    long long int dx1, dx2, dy1, dy2;
    dx1 = a[2] - a[0];
    dx2 = b[2] - b[0];
    dy1 = a[3] - a[1];
    dy2 = b[3] - b[1];
    if (!dx1 && !dx2 || !dy1 && !dy2)
    {
        printf("0");
        return 0;
    }
    if (!dx1 || !dx2 || !dy1 || !dy2)
    {
        if (!dx1) // x1 = x2 | a[0] == a[2]
        {
            if (!dy2)
            {
                if (a[1] <= b[1] && b[1] <= a[3] && b[0] <= a[0] && a[0] <= b[2])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
            else
            {
                if (dx2 * a[1] <= dy2 * (a[0] - b[0]) + dx2 * b[1] && dy2 * (a[0] - b[0]) + dx2 * b[1] <= dx2 * a[3])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
        }
        if (!dx2) // x3 = x4 || b[0] == b[2]
        {
            if (!dy1)
            {
                if (b[1] <= a[1] && a[1] <= b[3] && a[0] <= b[0] && b[0] <= a[2])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
            else
            {
                if (dx1 * b[1] <= dy1 * (b[0] - a[0]) + dx1 * a[1] && dy1 * (b[0] - a[0]) + dx1 * a[1] <= dx1 * b[3])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
        }
        if (!dy1) // y1 = y2 || a[1] == a[3]
        {
            if (!dx2)
            {
                if (b[1] <= a[1] && a[1] <= b[3] && a[0] <= b[0] && b[0] <= a[2])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
            else
            {
                if (dy2 * (a[0] - b[0]) + dx2 * b[1] <= dx2 * a[1] && dx2 * a[1] <= dy2 * (a[2] - b[0]) + dx2 * b[1])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
        }
        if (!dy2) // y3 = y4 || b[1] == b[3]
        {
            if (!dx1)
            {
                if (a[1] <= b[1] && b[1] <= a[3] && b[0] <= a[0] && a[0] <= b[2])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
            else
            {
                if (dy1 * (b[0] - a[0]) + dx1 * a[1] <= dx1 * b[1] && dx1 * b[1] <= dy1 * (b[2] - a[0]) + dx1 * a[1])
                    printf("1");
                else
                    printf("0");
                return 0;
            }
        }
    }
    else
    {
        s = max(a[0], b[0]);
        e = min(a[2], b[2]);
        if (s > e)
        {
            printf("0");
            return 0;
        }
        long long int weight, result;
        weight = dx2 * dy1 - dx1 * dy2;
        result = (dx2 * dy1) * a[0] - (dx1 * dy2) * b[0] + (dx2 * dx1) * (b[1] - a[1]);
        if (min(weight * s, weight * e) <= result && result <= max(weight * s, weight * e))
            printf("1");
        else
            printf("0");
    }
    return 0;
}