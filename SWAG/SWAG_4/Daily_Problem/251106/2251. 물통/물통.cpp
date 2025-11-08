#include <bits/stdc++.h>
using namespace std;
int visited[201][201][201];
int ma, mb, mc;
vector<int> res;
void bottle(int a, int b, int c)
{
    if (visited[a][b][c])
        return;
    visited[a][b][c] = 1;
    if (ma - a < b)
        bottle(ma, a + b - ma, c);
    else
        bottle(a + b, 0, c);
    if (mb - b < a)
        bottle(a + b - mb, mb, c);
    else
        bottle(0, a + b, c);

    if (ma - a < c)
        bottle(ma, b, a + c - ma);
    else
        bottle(a + c, b, 0);
    if (mc - c < a)
        bottle(a + c - mc, b, mc);
    else
        bottle(0, b, a + c);

    if (mb - b < c)
        bottle(a, mb, b + c - mb);
    else
        bottle(a, b + c, 0);
    if (mc - c < b)
        bottle(a, b + c - mc, mc);
    else
        bottle(a, 0, b + c);
}
int main()
{
    scanf("%d%d%d", &ma, &mb, &mc);
    bottle(0, 0, mc);
    for (int i = 0; i <= mb; i++)
    {
        for (int j = 0; j <= mc; j++)
        {
            if (visited[0][i][j])
                res.push_back(j);
        }
    }
    res.erase(unique(res.begin(), res.end()), res.end());
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
}