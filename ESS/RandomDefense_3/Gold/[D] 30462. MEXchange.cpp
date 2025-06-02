#include <bits/stdc++.h>
using namespace std;
int s[200001] = {
    0,
};
void MEX(int n)
{
    stack<int> t;
    t.push(s[n - 2]);
    for (int i = n - 2; i >= 1; i--)
    {
        if (n - 2)
    }
}
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        if (s[i] > i + 2)
            flag = 1;
    }
    if (s[n - 1] != n + 1)
        flag = 1;
    if (flag)
        printf("No");
    else
        MEX(n);
    return 0;
}