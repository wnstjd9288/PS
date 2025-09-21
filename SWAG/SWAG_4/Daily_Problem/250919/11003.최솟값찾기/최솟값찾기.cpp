#include <bits/stdc++.h>
using namespace std;
int arr[5000001];
int main()
{
    int n, l;
    deque<pair<int, int>> dq;

    scanf("%d%d", &n, &l);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
    {
        if (i >= l)
            if (dq.front().second == i - l)
                dq.pop_front();
        if (!dq.empty())
        {
            while (!dq.empty() && dq.back().first > arr[i])
            {
                dq.pop_back();
            }
        }
        dq.push_back({arr[i], i});
        printf("%d ", dq.front().first);
    }

    return 0;
}