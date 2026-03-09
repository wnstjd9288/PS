#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int LIS[100001] = {
    0,
};
int record[100001] = {
    0,
};
int result[100001] = {
    0,
};
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
        return a.first < b.first;
}

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
    int n, total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        vec.push_back({a, b});
        record[i] = result[i] = -1;
    }
    sort(vec.begin(), vec.end(), cmp);

    int cnt = -1;
    int cur = vec[0].first;
    LIS[++cnt] = vec[0].second;
    record[cnt] = cnt;

    for (int i = 1; i < n; i++)
    {
        if (vec[i].first == cur)
            continue;
        if (LIS[cnt] < vec[i].second)
        {
            LIS[++cnt] = vec[i].second;
            cur = vec[i].first;
            record[i] = cnt;
        }
        else
        {
            int index = lo_bound(cnt + 1, 0, vec[i].second);
            if (vec[i].second != LIS[index])
            {
                LIS[index] = vec[i].second;
                record[i] = index;
            }
        }
    }
    if (cnt < 2)
    {
        printf("-1");
        return 0;
    }
    int mid = cnt / 2;
    total += cnt + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (record[i] == cnt)
        {
            result[i] = cnt;
            cnt--;
        }
    }

    int mid_x, mid_y, mid_i;
    for (int i = 0; i < n; i++)
    {
        if (result[i] == mid)
        {
            mid_x = vec[i].first;
            mid_y = vec[i].second;
            mid_i = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        LIS[i] = 0;
        result[i] = record[i] = -1;
    }
    cnt = -1;
    cur = mid_x;
    LIS[++cnt] = mid_y;
    record[cnt] = cnt;
    for (int i = mid_i + 1; i < n; i++)
    {
        if (LIS[cnt] > vec[i].second)
        {
            LIS[++cnt] = vec[i].second;
            cur = vec[i].first;
            record[i] = cnt;
        }
        else
        {
            int index = lo_bound(cnt + 1, 0, vec[i].second);
            if (vec[i].second != LIS[index])
            {
                LIS[index] = vec[i].second;
                record[i] = index;
            }
        }
    }
    total += cnt;

    for (int i = 0; i < n; i++)
    {
        LIS[i] = 0;
        result[i] = record[i] = -1;
    }
    cnt = -1;
    cur = mid_x;
    LIS[++cnt] = mid_y;
    record[cnt] = cnt;
    for (int i = mid_i - 1; i >= 0; i--)
    {
        if (LIS[cnt] > vec[i].second)
        {
            LIS[++cnt] = vec[i].second;
            cur = vec[i].first;
            record[i] = cnt;
        }
        else
        {
            int index = lo_bound(cnt + 1, 0, vec[i].second);
            if (vec[i].second != LIS[index])
            {
                LIS[index] = vec[i].second;
                record[i] = index;
            }
        }
    }
    total += cnt;
    printf("%d",n-total);
}