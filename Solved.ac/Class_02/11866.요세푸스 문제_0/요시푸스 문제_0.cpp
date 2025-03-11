#include <stdio.h>

int main()
{
    int s[1001];
    int n, k;
    int cnt;
    int h = 0, t = -1;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
        s[++t] = i;

    cnt = k - 1;
    printf("<%d", k);

    while (h != t)
    {
        for (int i = cnt; i < t; i++)
        {
            s[i] = s[i + 1];
        }
        t--;
        n--;
        cnt += k - 1;
        cnt %= n;

        printf(", %d", s[cnt]);
    }
    printf(">");
    return 0;
}