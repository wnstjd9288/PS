#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<int> arr;
    vector<int> arr_o;
    unordered_map<int, int> exist;
    unordered_map<int, int> result;
    scanf("%d", &t);
    for (int i = 0; i < 6; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
        arr_o.push_back(a);
        exist[a]++;
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    if (t == 1)
    {
        int m = -1;
        int n = arr.size();
        int start;
        for (int i = 0; i < n; i++)
        {
            int next = arr[(i + 1) % n] - arr[i];
            if (next < 0)
                next += 64;
            if (m < next)
            {
                start = (i + 1) % n;
                m = next;
            }
        }
        for (int i = start; i < start + n; i++)
        {
            for (int j = 1;; j++)
            {
                int next = arr[i % n] + j;
                if (next >= 65)
                    next -= 64;
                if (!exist[next])
                {
                    exist[next]++;
                    result[arr[i % n]] = next;
                    break;
                }
            }
        }
        for (int i = 0; i < 6; i++)
            printf("%d ", result[arr_o[i]]);
    }
    else
    {
        int m = -1;
        int n = arr.size();
        int start;
        for (int i = 0; i < n; i++)
        {
            int next = arr[(i + 1) % n] - arr[i];
            if (next < 0)
                next += 64;
            if (m < next)
            {
                start = i;
                m = next;
            }
        }
        for (int i = start + n; i > start; i--)
        {
            for (int j = 63;; j--)
            {
                int next = (arr[i % n] + j);
                if (next >= 65)
                    next -= 64;
                if (!exist[next])
                {
                    exist[next]++;
                    result[arr[i % n]] = next;
                    break;
                }
            }
        }
        for (int i = 0; i < 6; i++)
            printf("%d ", result[arr_o[i]]);
    }
    return 0;
}