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
        int cnt = 0;
        int high = 0;
        int low = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i <= n; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (a == k)
            {
                cnt++;
                continue;
            }
            else if (a > k)
                high++;
            if (visited[a] && a < k)
                low++;
            visited[a] = 1;
        }
        int need = k - (n - (cnt + high) - low);
        need = max(need, cnt);
        printf("%d\n", need);
    }
}