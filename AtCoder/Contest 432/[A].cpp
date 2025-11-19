#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    for (int i = 0; i < 3; i++)
    {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (int i = 2; i >= 0; i--)
    {
        printf("%d",arr[i]);
    }
}