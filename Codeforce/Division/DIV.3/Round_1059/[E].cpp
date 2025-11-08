#include <bits/stdc++.h>
using namespace std;
int visited[200001];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        vector<int> vec, arr;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            arr.push_back(a);
            visited[a]++;
        }
        int a = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                a = i;
                break;
            }
        }
        if (a == -1)
            vec = {arr[n - 3], arr[n - 2], arr[n - 1]};
        else
        {
            int b = -1;
            for (int i = 1; i <= n; i++)
            {
                if (i != a && i != arr[n - 1])
                {
                    b = i;
                    break;
                }
            }
            vec = {a, b, arr[n - 1]};
        }
        for (int i = 0; i < k; i++)
        {
            printf("%d ", vec[i % 3]);
        }
        puts("");
        for (int i = 0; i <= n; i++)
            visited[i] = 0;
    }
}