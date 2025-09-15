#include <bits/stdc++.h>
int arr[100001] = {
    0,
};
int tree[500001] = {
    0,
};

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
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    init(0, n-1, 1);
    for (int i = 0; i < m; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", sum(1, n, 1, start, end));
    }

    return 0;
}