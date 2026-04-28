#include <bits/stdc++.h>
using namespace std;
char s[100001];
bool check(int t, int n)
{
    int cnt[6]={0,};
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 's':
            cnt[0]++;
            break;
        case 'o':
            if (cnt[0] > 0)
            {
                cnt[0]--;
                cnt[1]++;
            }
            break;
        case 'g':
            if (cnt[1] > 0 && cnt[2] + cnt[3] + cnt[4] + res < t)
            {
                cnt[1]--;
                cnt[2]++;
            }
            else if (cnt[4] > 0)
            {
                cnt[4]--;
                cnt[5]++;
                res++;
            }
            break;
        case 'a':
            if (cnt[2] > 0)
            {
                cnt[2]--;
                cnt[3]++;
            }
            break;
        case 'n':
            if (cnt[3] > 0)
            {
                cnt[3]--;
                cnt[4]++;
            }
            break;
        }
    }
    return res >= t;
}
int main()
{
    int n;
    scanf("%d%s", &n, s);
    int low = 0, high = n / 6, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == 0)
        {
            low = mid + 1;
            continue;
        }
        if (check(mid, n))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%d", ans);
}