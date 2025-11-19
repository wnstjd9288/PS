#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
unordered_map<int, int> m;
int tree[2000001];
int init(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, int dif)
{
    if (index < start || index > end)
        return;
    tree[node] += dif;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}
int lo_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (arr[mid] < k)
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
        if (arr[mid] <= k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    init(0, n - 1, 1);
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            m[b - 1] = c;
        }
        else
        {
            if (b >= c)
            {
                printf("%lld\n", b * n);
            }
            else
            {
                int left = lo_bound(b, 0, n), right = up_bound(c, 0, n);
                long long int res = left * b + (n - right) * c;
                res += sum(0, n - 1, 1, left, right - 1);
                for (auto iter = m.begin(); iter != m.end(); iter++)
                {
                    if (arr[iter->first] <= b)
                        res -= b;
                    else if (arr[iter->first] >= c)
                        res -= c;
                    else
                    {
                        res -= arr[iter->first];
                    }
                    res += clamp(iter->second, left, right);
                }
                printf("%lld\n", res);
            }
        }
    }
}