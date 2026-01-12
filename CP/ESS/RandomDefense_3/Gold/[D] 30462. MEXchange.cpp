#include <bits/stdc++.h>
using namespace std;
int s[200001] = {
    0,
};
int visited[200001] = {
    0,
};
int result[200001] = {
    0,
};
void MEX(int n)
{
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            result[i] = s[i - 1];
            visited[s[i - 1]] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (result[i])
            printf("%d ", result[i]);
        else
        {
            while (visited[cnt])
                cnt++;
            printf("%d ", cnt);
            cnt++;
        }
    }
}
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        if (i && s[i - 1] > s[i])
            flag = 1;
        if (s[i] > i + 2)
            flag = 1;
    }
    if (s[n - 1] != n + 1)
        flag = 1;
    if (flag)
        printf("No");
    else
    {
        printf("Yes\n");
        MEX(n);
    }
    return 0;
}