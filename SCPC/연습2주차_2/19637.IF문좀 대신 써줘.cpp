#include <bits/stdc++.h>
using namespace std;
char s[100001][12];
char ans[100001][12];
int power[100001];
vector<pair<int, int>> arr;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", s[i], &power[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        arr.push_back({k, i});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[i].first > power[cnt])
        {
            while (arr[i].first > power[cnt])
            {
                cnt++;
            }
        }
        strcpy(ans[arr[i].second],s[cnt]);
    }
    for(int i=0;i<m;i++){
        printf("%s\n",ans[i]);
    }
}