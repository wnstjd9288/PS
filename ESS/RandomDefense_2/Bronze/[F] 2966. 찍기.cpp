#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res[3] = {
               0,
           };
    char s[101];
    char a[3] = {'A', 'B', 'C'}, b[4] = {'B', 'A', 'B', 'C'}, c[6] = {'C', 'C', 'A', 'A', 'B', 'B'};
    int m = -1;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == a[i % 3])
            res[0]++;
        if (s[i] == b[i % 4])
            res[1]++;
        if (s[i] == c[i % 6])
            res[2]++;
    }
    for (int i = 0; i < 3; i++)
        m = max(m, res[i]);
    printf("%d", m);

    if (res[0] == m)
        printf("\nAdrian");
    if (res[1] == m)
        printf("\nBruno");
    if (res[2] == m)
        printf("\nGoran");
    return 0;
}