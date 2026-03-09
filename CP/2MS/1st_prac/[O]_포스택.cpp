#include <bits/stdc++.h>
int arr[100001];
int main()
{
    int n;
    int stack[4] = {
        0,
    };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int select = -1;
        for (int j = 0; j < 4; j++)
        {
            if (arr[i] > stack[j])
            {
                if (select == -1)
                    select = j;
                else
                {
                    if (stack[j] > stack[select])
                        select = j;
                }
            }
        }
        if (select == -1)
        {
            printf("NO");
            return 0;
        }
        else
        {
            stack[select] = arr[i];
        }
    }
    printf("YES");
    return 0;
}