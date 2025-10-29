#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr, arr_s;
unordered_map<int, int> visited;
long long tree[4000001];
long long sum(int s, int e, int n, int x, int y)
{
    if (x > e || y < s)
        return 0;
    if (x <= s && y >= e)
        return tree[n];
    int mid = (s + e) / 2;
    return sum(s, mid, n * 2, x, y) +
           sum(mid + 1, e, n * 2 + 1, x, y);
}
void update(int s, int e, int n, int x)
{
    if (x < s || x > e)
        return;
    tree[n]++;
    if (s == e)
        return;
    int mid = (s + e) / 2;
    update(s, mid, n * 2, x);
    update(mid + 1, e, n * 2 + 1, x);
}
int lo_bound(int k, int s, int e)
{
    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (arr_s[mid].first < k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int up_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (arr_s[mid].first <= k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int main()
{
    int n;
    long long cnt = 0;
    scanf("%d", &n);
    arr.resize(n);
    arr_s.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    copy(arr.begin(), arr.end(), arr_s.begin());
    sort(arr_s.begin(), arr_s.end());

    for (int i = 0; i < n; i++)
    {
        if (visited[arr_s[i].first])
            continue;
        visited[arr_s[i].first] = 1;
        int start = lo_bound(arr_s[i].first, 0, n);
        int end = up_bound(arr_s[i].first, 0, n);
        for (int j = start; j < end; j++)
        {
            cnt += sum(0, n - 1, 1, arr_s[j].second, n - 1);
        }
        for (int j = start; j < end; j++)
        {
            update(0, n - 1, 1, arr_s[j].second);
        }
    }
    printf("%lld", cnt);
}