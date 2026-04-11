#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, s;
    vector<int> a, b;
    vector<pair<double, int>> p;
    vector<int> result;
    scanf("%d%d%d", &n, &m, &s);
    a.resize(n);
    b.resize(n);
    result.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        p.push_back({(double)b[i] / (double)a[i], i});
    }
    sort(p.begin(), p.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        int now = p[i].second;
        int value = min(s, m);
        result[p[i].second] += min(a[p[i].second], value);
        s -= min(a[p[i].second], value);
        if (s == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
}