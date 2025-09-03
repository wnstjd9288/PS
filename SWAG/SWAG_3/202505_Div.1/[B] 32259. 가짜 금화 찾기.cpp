#include <bits/stdc++.h>
using namespace std;
int result(int n)
{
    int coin[129] = {
        0,
    };
    for (int i = 0; i < 7; i++)
    {
        char ans;
        int k = 0, k_copy, check1, check2;
        for (int j = 1; j <= n; j++)
        {
            if (coin[j] == i)
            {
                k++;
                coin[j]++;
            }
        }
        if (k <= 3)
        {
            if (k == 1)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                        return j;
                }
            }
            else if (k == 2)
            {
                int c1, c2;
                for (int j = 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        c1 = j;
                        break;
                    }
                }
                for (int j = c1 + 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        c2 = j;
                        break;
                    }
                }
                printf("? %d 0 %d 0\n", c1, c2);
                scanf("%1c%*c", &ans);
                if (ans == '>')
                    return c2;
                else
                    return c1;
            }
            else
            {
                int c1, c2, c3;
                for (int j = 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        c1 = j;
                        break;
                    }
                }
                for (int j = c1 + 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        c2 = j;
                        break;
                    }
                }
                for (int j = c2 + 1; j <= n; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        c3 = j;
                        break;
                    }
                }
                printf("? %d 0 %d 0\n", c1, c2);
                scanf("%1c%*c", &ans);
                if (ans == '>')
                    return c2;
                else if (ans == '<')
                    return c1;
                else
                    return c3;
            }
        }
        k_copy = k / 3;
        printf("? ");
        for (int j = 1; j <= n; j++)
        {
            if (coin[j] == i + 1)
            {
                printf("%d ", j);
                k_copy--;
            }
            if (!k_copy)
            {
                check1 = j;
                break;
            }
        }
        k_copy = k / 3;
        printf("0 ");
        for (int j = check1 + 1; j <= n; j++)
        {
            if (coin[j] == i + 1)
            {
                printf("%d ", j);
                k_copy--;
            }
            if (!k_copy)
            {
                check2 = j;
                break;
            }
        }
        printf("0\n");
        scanf("%1c%*c", &ans);
        if (ans == '=')
        {
            for (int j = check2 + 1; j <= n; j++)
            {
                if (coin[j] == i + 1)
                {
                    coin[j]++;
                }
            }
        }
        else if (ans == '>')
        {
            if (k / 3 == 1)
            {
                for (int j = check1 + 1; j <= check2; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        return j;
                    }
                }
            }
            for (int j = check1 + 1; j <= check2; j++)
            {
                if (coin[j] == i + 1)
                {
                    coin[j]++;
                }
            }
            int cnt = 0;
            for (int j = n; j >= 1; j--)
            {
                if (cnt == k % 3)
                    break;
                if (coin[j] == i + 1)
                {
                    coin[j]++;
                    cnt++;
                }
            }
        }
        else
        {
            if (k / 3 == 1)
            {
                for (int j = 1; j <= check1; j++)
                {
                    if (coin[j] == i + 1)
                    {
                        return j;
                    }
                }
            }
            for (int j = 1; j <= check1; j++)
            {
                if (coin[j] == i + 1)
                {
                    coin[j]++;
                }
            }
            int cnt = 0;
            for (int j = n; j >= 1; j--)
            {
                if (cnt == k % 3)
                    break;
                if (coin[j] == i + 1)
                {
                    coin[j]++;
                    cnt++;
                }
            }
        }
        i++;
    }
    return 1;
}
int main()
{
    int n, res;
    scanf("%d%*c", &n);
    printf("! %d", result(n));
    return 0;
}