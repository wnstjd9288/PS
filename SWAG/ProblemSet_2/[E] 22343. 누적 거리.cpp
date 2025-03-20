#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, q;
    vector<pair<int, int>> village;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        int x, a;
        scanf("%d %d", &a, &x);
        village.push_back(make_pair(a, x));
    }
    sort(village.begin(), village.end(), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", village[i].first, village[i].second);
    }
    return 0;
}