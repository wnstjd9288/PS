#include <stdio.h>
int s[1000001] = {
    0,
};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    s[1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        if (s[i])
            continue;
        for (int j = i * i; j <= 1000000; j += i)
            s[j] = 1;
    }
    for (int i = n; i <= m; i++)
        if (!s[i])
            printf("%d\n", i);
    return 0;
}