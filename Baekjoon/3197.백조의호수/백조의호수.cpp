#include <bits/stdc++.h>
using namespace std;
int tree[10000001] = {
    0,
};
int arr[1501][1501] = {
    0,
};
int visited[1501][1501] = {
    0,
};
void Flood_Fill(int x, int y, int cnt)
{
}
int main()
{
    int n, m;
    int cnt = 0;
    vector<pair<int, int>> quack;
    char s[1501];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'X')
            {
                arr[i][j] = -1;
                visited[i][j] = -1;
            }
            if (s[j] == 'L')
            {
                quack[cnt][0] = i;
                quack[cnt][1] = j;
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!arr[i][j] && !visited[i][j])
            {
                cnt++;
                Flood_Fill(i, j, cnt);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%2d ", arr[i][j]);
        puts("");
    }
}