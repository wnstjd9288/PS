#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> idx;
vector<int> idxvec;
int arr[300001];
int cnt[300001];
int stick[2];
int main()
{
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (!i)
        {
            if (!arr[i])
                cnt[i] = 1;
            else
            {
                idx[i] = 1;
                idxvec.push_back(i);
                cnt[i] = 0;
            }
        }
        else
        {
            if (arr[i] == arr[i - 1])
                cnt[i] = cnt[i - 1] + 1;
            else
            {
                idx[i] = 1;
                idxvec.push_back(i);
                cnt[i] = 0;
            }
        }
    }
    idx[n - 1] = 1;
    idxvec.push_back(n - 1);
    for (auto [x, y] : idx)
        stick[arr[x - 1]] += cnt[x - 1];
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        if (arr[a] == arr[b])
            printf("%d %d\n", stick[0], stick[1]);
        else
        {
            if (idx[a] || idx[b])
            {
            }
            else
            {
                int lb = lower_bound(idxvec.begin(), idxvec.end(), a);
                int next = arr[lb];
                int prev = arr[lb - 1];
                if ()
            }
        }
    }
    return 0;
}