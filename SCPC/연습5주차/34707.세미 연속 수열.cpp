#include <bits/stdc++.h>
using namespace std;
set<int> s;
int arr[500001];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        s.insert(arr[i]);
        if (i >= k)
        {
            s.erase(s.find(arr[i - k]));
        }
        if (i >= k - 1)
        {
            if (*s.rbegin() - *s.begin() == k - 1)
            {
                printf("YES\n");
                for (int j = i - k + 1; j <= i; j++)
                {
                    printf("%d ", arr[j]);
                }
                return 0;
            }
        }
    }
    printf("NO");
}