#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, int>> arr, ori;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back({a, i});
        ori.push_back({a, 0});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++){
        ori[arr[i].second].second = i + 1;
    }
    for (int i = 0; i < n; i++){
        printf("%d %d\n",ori[i].first,ori[i].second);
    }
    return 0;
}