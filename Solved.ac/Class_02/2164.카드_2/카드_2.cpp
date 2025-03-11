#include <stdio.h>
<<<<<<< HEAD

    int
    main()
{
    int n;
    int que[10000001] = {
        0,
    };
    int h = 0, t = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        que[++t] = i;
    }
    while (h != t)
    {
        h++;
        que[++t] = que[h++];
    }
    printf("%d", que[t]);
    return 0;
}