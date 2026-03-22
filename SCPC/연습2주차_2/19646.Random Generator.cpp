
#include <bits/stdc++.h>
int tree[5000001];
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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, n - 1, 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int s = 0, e = n;
        int piv;
        while (1)
        {
            piv = (s + e) / 2;
            int k = sum(0, n - 1, 1, 0, piv);
            int km = sum(0, n - 1, 1, 0, piv - 1);
            if (km < a[i] && k >= a[i])
            {
                update(0, n - 1, 1, piv, -arr[piv]);
                printf("%d ", piv + 1);
                break;
            }
            if (km >= a[i])
                e = piv;
            if (k < a[i])
                s = piv;
        }
    }
    return 0;
}