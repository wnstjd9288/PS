#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> arr;
int lower[200001], upper[200001];
unordered_map<int, int> m;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, l, r;
        int cnt = 0;
        scanf("%d%d%d%d", &n, &k, &l, &r);
        arr.clear();
        m.clear();
        memset(lower, 0, sizeof(int) * n);
        memset(upper, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            arr.push_back(a);
        }
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            if (m.size() == k)
            {
                if (index == -1)
                    index = i;
                upper[i] = upper[i - 1];
            }
            else if (m.size() > k)
            {
                int a = upper[i - 1];
                while (m.size() > k)
                {
                    m[arr[a]]--;
                    a++;
                }
            }
        }
    }
}