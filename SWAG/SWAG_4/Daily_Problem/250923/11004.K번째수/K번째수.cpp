#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    printf("%d", vec[k - 1]);
}