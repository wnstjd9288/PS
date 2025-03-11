#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pri;
    int index;
} File;

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int n, m;
        int pri[101] = {0};
        int h = 0, t = -1;
        int pri_top = 0;
        File file[100001];
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &pri[++t]);
            file[t].pri = pri[t];
            file[t].index = t;
        }
        qsort(pri, n, sizeof(int), cmp);
        while (h <= t)
        {
            if (file[h].pri == pri[pri_top])
            {
                if (file[h].index == m)
                {
                    printf("%d\n", pri_top + 1);
                    break;
                }
                pri_top++;
                h++;
            }
            else
            {
                file[++t] = file[h++];
            }
        }
    }
    return 0;
}