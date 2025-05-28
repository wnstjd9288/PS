#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> s;
int main()
{
    int n, cnt = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        s.push_back({a, b});
    }
    sort(s.begin(), s.end());
    int start = s[0].first + s[0].second;
    for (int i = 1; i < n; i++)
    {
        if (s[i].first > start)
            cnt++;
        start = s[i].first + s[i].second;
    }
    printf("%d", cnt);
    return 0;
}