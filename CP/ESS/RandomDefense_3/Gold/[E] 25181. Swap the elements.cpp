#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
vector<pair<int, int>> v;
vector<vector<int>> check(100001);
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    int n;
    int s[5001], result[5001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        m[s[i]]++;
        check[s[i]].push_back(i);
    }
    for (auto p : m)
    {
        v.push_back({p.first, p.second});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
    if (v[0].second > n / 2)
    {
        printf("-1");
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            int cnt = v[i].second;
            for (int j = 1; cnt; j++)
            {
                int k = 0;
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d ", result[i]);
    }
    return 0;
}