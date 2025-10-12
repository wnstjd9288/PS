#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr;
vector<pair<int, int>> arr_cp;
int visited[500001];
int tree[4000001];
int sum(int s, int e, int n, int x, int y)
{
    if (x < s || y > e)
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
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    arr.resize(n + 1);
    arr_cp.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    copy(arr.begin(), arr.end(), arr_cp.begin());
    for (int i = n - 1; i >= 0; i--)
    {
        update(0, n - 1, 1, arr[i]);
        cnt += sum(0, n - 1, 1, arr[i], n - 1);
    }
}