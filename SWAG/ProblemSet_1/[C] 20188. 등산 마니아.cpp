#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a[300001];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(make_pair(y, a[x].size() + 1));
        a[y].push_back(make_pair(x, a[y].size() + 1));
    }
    printf("res\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            printf("(%d,%d) ", a[i][j].first, a[i][j].second);
        }
        puts("");
    }
    return 0;
}