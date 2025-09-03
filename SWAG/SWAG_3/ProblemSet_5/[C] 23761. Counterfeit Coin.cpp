#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int start = 1, end = n;
    char str[10];
    int flag = 0;
    while (1)
    {
        if (flag == 11)
        {
            printf("? %d %d\n", start, end);
            fflush(stdout);
            scanf("%s", str);
            if (str[0] == 'e')
            {
                printf("! %d", end - 1);
            }
            else
                printf("! %d", start);
            return 0;
        }
        if (start == end)
        {
            printf("! %d", start);
            return 0;
        }
        printf("? %d %d\n", start, end);
        fflush(stdout);
        scanf("%s", str);
        if (str[0] == 'e')
        {
            if (flag == 1)
            {
                printf("! %d", end + 1);
                return 0;
            }
            if (flag == -1)
            {
                printf("! %d", end + 1);
                return 0;
            }
            start++;
            end--;
            if (end - start == 1)
            {
                flag = 11;
                end++;
            }
        }
        else if (str[0] == 'l') // x < y
        {
            if (flag == 1)
            {
                printf("! %d", start);
                return 0;
            }
            end--;
            flag = 1;
        }
        else // x > y
        {
            if (flag == -1)
            {
                printf("! %d", start);
                return 0;
            }
            end--;
            flag = -1;
        }
    }
}