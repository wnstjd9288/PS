#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n, k, x;
        int start, end, mid;
        unordered_map<int, int> m;
        unordered_map<int, int> result;
        priority_queue<pair<pair<int, int>, bool>> pq; // <<dis,cod>,l/r(t/f)>
        vector<int> arr;
        scanf("%d%d%d", &n, &k, &x);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        pq.push({{arr[0], 0}, false});
        m[0] = 1;
        pq.push({{x - arr[n - 1], x}, true});
        m[x] = 1;
        for (int i = 1; i < n; i++)
        {
            start = arr[i - 1];
            end = arr[i];
            mid = (start + end) / 2;
            if ((start + end) % 2)
            {
                if (!m[mid])
                {
                    pq.push({{mid - start, mid}, true});
                    m[mid] = 1;
                }
                if (!m[mid + 1])
                {
                    pq.push({{end - (mid + 1), mid + 1}, false});
                    m[mid + 1] = 1;
                }
            }
            else
            {
                if (!m[mid])
                {
                    pq.push({{mid - start, mid}, true});
                    pq.push({{end - mid, mid}, true});
                    m[mid] = 1;
                }
            }
        }
        while (k--)
        {
            if (!result[pq.top().first.second])
            {
                printf("%d ", pq.top().first.second);
                result[pq.top().first.second] = 1;
            }
            else
                k++;
            pair<pair<int, int>, bool> next = pq.top();
            pq.pop();
            next.first.first--;
            if (next.second)
                next.first.second--;
            else
                next.first.second++;
            if (!m[next.first.second])
            {
                pq.push(next);
                m[next.first.second] = 1;
            }
        }
        puts("");
    }
}