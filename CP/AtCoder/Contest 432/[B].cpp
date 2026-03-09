#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int a, cnt = 0;
    scanf("%d", &a);
    while (a)
    {
        arr.push_back(a % 10);
        a /= 10;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (!arr[i])
            cnt++;
        else
        {
            printf("%d", arr[i]);
            for (int i = 0; i < cnt; i++)
                printf("0");
            cnt = 0;
        }
    }
}