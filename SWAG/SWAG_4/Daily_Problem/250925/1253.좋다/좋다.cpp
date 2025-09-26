#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
bool is_good[2001];
int up_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (vec[mid] <= k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int lo_bound(int k, int s, int e)
{

    int mid;
    while (e - s > 0)
    {
        mid = (s + e) / 2;
        if (vec[mid] < k)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = vec[i] + vec[j];
            int lo = lo_bound(sum, 0, n);
            if (is_good[lo])
                continue;
            int up = up_bound(sum, 0, n);
            if (vec[lo_bound(sum, 0, n)] == sum)
            {
                if (lo == i || lo == j)
                {
                    if (up - lo == 1)
                        continue;
                    if (vec[i] == vec[j] && up - lo <= 2)
                        continue;
                }
                for (int k = lo; k < up; k++)
                    is_good[k] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (is_good[i])
            cnt++;
    printf("%d", cnt);
}