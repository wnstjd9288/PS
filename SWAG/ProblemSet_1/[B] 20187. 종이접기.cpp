#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int row;
    int column;
} grid;
grid map[256][256] = {
    0,
};
char s[16];
int main()
{
    int n, m;
    int now = 1;
    int scale = 1;
    grid cnt = 0, start;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scale *= 2;
    for (int i = 0; i < n * 2; i++)
    {
        scanf("%*c%1c", &s[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < scale; i++)
    {
        for (int j = 0; j < scale; j++)
        {
            map[i][j].column = j;
            map[i][j].row = i;
        }
    }
    for (int i = 0; i < n * 2; i++)
    {
        switch (s[i])
        {
        case 'R':
            for (int j = 0; j < scale; j++)
            {
                for (int k = 0; k < scale / 2; k++)
                {
                }
            }
            break;
        case 'D':
            break;
        case 'L':
            break;
        case 'U':
            break;
        default:
            break;
        }
    }
    return 0;
}