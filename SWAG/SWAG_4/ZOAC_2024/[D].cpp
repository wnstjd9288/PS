#include <bits/stdc++.h>
int tree[2000001];
int arr[500001];
int a[500001];

int init(int s, int e, int n)
{
    if (s == e)
        return tree[n] = arr[s];
    int mid = (s + e) / 2;
    return tree[n] = init(s, mid, n * 2) +
                     init(mid + 1, e, n * 2 + 1);
}
int sum(int s, int e, int n, int x, int y)
{
    if (x > e || y < s)
        return 0;
    if (x <= s && e <= y)
        return tree[n];
    int mid = (s + e) / 2;
    return sum(s, mid, n * 2, x, y) + sum(mid + 1, e, n * 2 + 1, x, y);
}
void update(int s, int e, int n, int idx, int dif)
{
    if (idx > e || idx < s)
        return;
    tree[n] += dif;
    if (s == e)
        return;
    int mid = (s + e) / 2;
    update(s, mid, n * 2, idx, dif);
    update(mid + 1, e, n * 2 + 1, idx, dif);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, n - 1, 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int res = sum(0, n - 1, 1, 0, a[i] - 2);
        printf("%d ", res + 1);
        update(0, n - 1, 1, a[i] - 1, arr[a[i] - 1] * (-1));
    }
    return 0;
}