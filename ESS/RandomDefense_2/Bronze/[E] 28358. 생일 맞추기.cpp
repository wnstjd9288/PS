#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int s[10];
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &s[i]);
        }
        for (int i = 1; i <= 12; i++)
        {
            for (int j = 1; j <= 31; j++)
            {
                if (i == 2 && j == 30)
                    break;
                if (i == 4 || i == 6 || i == 9 || i == 11)
                {
                    if (j == 31)
                        break;
                }
                if (i >= 10)
                {
                    if (s[i / 10] || s[i % 10])
                        continue;
                }
                else
                {
                    if (s[i])
                        continue;
                }
                if (j >= 10)
                {
                    if (s[j / 10] || s[j % 10])
                        continue;
                }
                else
                {
                    if (s[j])
                        continue;
                }
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}