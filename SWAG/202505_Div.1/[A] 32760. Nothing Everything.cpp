#include <bits/stdc++.h>
using namespace std;
vector<int> g1[100001];
vector<char> res;
int result(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < g1[i].size(); j++)
        {
            if (g1[i][j] < i)
                cnt++;
        }
        if (cnt == i - 1)
            res.push_back('E');
        else if (cnt == 0)
            res.push_back('N');
        else
            return 0;
    }
    return 1;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    if (result(n))
    {
        for (int i = 0; i < res.size(); i++)
            printf("%c", res[i]);
    }
    else
        printf("-1");
    return 0;
}