#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int arr[4];
        bool flag = true;
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &arr[j]);
            if (j && arr[j] != arr[j - 1])
                flag = false;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}