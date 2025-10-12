#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++)
        sum += vec[n - i] * i;
    printf("%d", sum);
}