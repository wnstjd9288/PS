#include <bits/stdc++.h>
using namespace std;
int visited[201][201][201];
int m_arr[3];
pair<int, int> mv[] = {
    {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
vector<int> res;
void bottle(int a, int b, int c)
{

    if (visited[a][b][c])
        return;
    visited[a][b][c] = 1;
    printf("%d %d %d\n",a,b,c);
    int arr[3] = {a, b, c};
    for (auto [src, dst] : mv)
    {
        if (m_arr[src] - arr[src] < arr[dst])
        {
            arr[dst] = arr[src] + arr[dst] - m_arr[src];
            arr[src] = m_arr[src];
        }
        else
        {
            arr[src] = arr[src] + arr[dst];
            arr[dst] = 0;
        }
        bottle(arr[0], arr[1], arr[2]);
    }
}
int main()
{
    for (int i = 0; i < 3; i++)
        scanf("%d", &m_arr[i]);
    bottle(0, 0, m_arr[2]);
    for (int i = 0; i <= m_arr[1]; i++)
    {
        for (int j = 0; j <= m_arr[2]; j++)
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