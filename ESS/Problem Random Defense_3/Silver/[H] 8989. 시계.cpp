#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<float, pair<int, int>> a, pair<float, pair<int, int>> b)
{
    if (a.first == b.first)
        return a.second.first * 60 + a.second.second < b.second.first * 60 + b.second.second;
    else
        return a.first < b.first;
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        vector<pair<float, pair<int, int>>> time;
        for (int i = 0; i < 5; i++)
        {
            int a, b;
            float h, m, deg;
            scanf("%d:%d", &a, &b);
            m = b;
            h = (a % 12) * 30 + m / 2;
            m = b * 6;
            deg = abs(h - m);
            if (deg > 180)
                deg = 360 - deg;
            time.push_back({deg, {a, b}});
        }
        sort(time.begin(), time.end(), cmp);
        if (time[2].second.first < 10)
            printf("0");
        printf("%d:", time[2].second.first);
        if (time[2].second.second < 10)
            printf("0");
        printf("%d\n", time[2].second.second);
    }
}