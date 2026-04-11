#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> arr;
    scanf("%d", &n);
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int s = 0, e = n - 1;
    int mex = 0, med = 0;
    int res = -1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (i % 2)
        {
            if (arr[s] == mex)
            {
                mex++;
                s++;
            }
            else
                break;
        }
        else
        {
            med = arr[e--];
        }
        res = max(res, mex + med);
    }
    if (i == n)
    {
        for (int i = s; i <= n; i++)
        {
            if (arr[i] == mex)
                mex++;
            else
                break;
        }
        res = max(res, mex + med);
    }
    printf("%d", res);
}