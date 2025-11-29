#include <bits/stdc++.h>
using namespace std;
int len[100001];
vector<vector<int>> arr;
unordered_map<int, int> arrmap[100001];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; j++)
        {
            int a;
            scanf("%d", &a);
            arr[i].push_back(a);
            arrmap[i][a]++;
        }
        arr[i].push_back(INT_MAX);
        sort(arr[i].begin(), arr[i].end());
    }
    for (int i = 0; i < q; i++)
    {
        int a, b, c, idx;
        scanf("%d %d %d %d", &a, &b, &c, &idx);
        a--, b--, c--;
        int sum = 0;
        int ai, bi, ci;
        ai = bi = ci = 0;
        int m = 0;
        while (sum < idx)
        {
            m = min(arr[c][ci], min(arr[a][ai], arr[b][bi]));
            sum += arrmap[a][m] + arrmap[b][m] + arrmap[c][m];
            ai += arrmap[a][m];
            bi += arrmap[b][m];
            ci += arrmap[c][m];
        }
        printf("%d\n", m);
    }
    return 0;
}