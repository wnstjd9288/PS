#include <bits/stdc++.h>
using namespace std;
int n, s, cnt = 0;
vector<int> arr;
void partial(int now, int sum)
{
    if (now == n || (sum > s && arr[now] > 0))
        return;
    if (sum + arr[now] == s)
        cnt++;
    partial(now + 1, sum + arr[now]);
    partial(now + 1, sum);
}
int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    partial(0, 0);
    printf("%d", cnt);
}