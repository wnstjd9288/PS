#include <stdio.h>

int main()
{
    int t, h, w, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int resh, resw;
        scanf("%d %d %d", &h, &w, &n);
        resh = n % h;
        resw = n / h + 1;
        if (resh == 0)
        {
            resh = h;
            resw = n / h;
        }

        printf("%d%02d\n", resh, resw);
    }

    return 0;
}