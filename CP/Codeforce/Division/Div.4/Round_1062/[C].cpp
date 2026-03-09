#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n;
        int odd = 0, even = 0;
        vector<int> arr;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            arr.push_back(a);
            if (a % 2)
                odd++;
            else
                even++;
        }
        if (odd && even)
        {
            sort(arr.begin(), arr.end());
        }
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        puts("");
    }
}