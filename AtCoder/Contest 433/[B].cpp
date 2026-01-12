#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[101];
stack<pair<int, int>> tall;
int res[101];
int main()
{
    int n;
    scanf("%d", &n);
    memset(res, -1, sizeof(res));
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr[i] = {a, i};
    }
    tall.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (tall.top().first > arr[i].first)
            res[i] = tall.top().second;
        else
        {
            while (tall.top().first <= arr[i].first)
            {
                tall.pop();
                if (tall.empty())
                    break;
            }
            if (!tall.empty())
                res[i] = tall.top().second;
        }
        tall.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", res[i] == -1 ? -1 : res[i] + 1);
}