#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int LIS[100001] = {
    0,
};
int record[100001] = {
    0,
};
int result[100001] = {
    0,
};
int lo_bound(int high, int low, int k)
{

    int mid;

    while (high > low)
    {
        mid = (high + low) / 2;
        if (LIS[mid] < k)
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return high;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int cnt = -1;
    LIS[++cnt] = v[0].second;
    record[cnt] = cnt;
    for (int i = 1; i < n; i++)
    {
        if (LIS[cnt] < v[i].second)
        {
            LIS[++cnt] = v[i].second;
            record[i] = cnt;
        }
        else
        {
            int index = lo_bound(cnt + 1, 0, v[i].second);
            LIS[index] = v[i].second;
            record[i] = index;
        }
    }

    printf("%d\n", n - 1 - cnt);
    for (int i = n - 1; i >= 0; i--)
    {
        if (record[i] == cnt)
        {
            result[i] = 1;
            cnt--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!result[i])
            printf("%d\n", v[i].first);
    }
}   