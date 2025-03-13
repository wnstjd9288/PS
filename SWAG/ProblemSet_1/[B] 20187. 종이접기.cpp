#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int row;
    int column;
} grid;
int map[256][256] = {
    0,
};
char s[16];
int main()
{
    int n, m;
    int now = 1;
    int scale = 1;
    grid cnt = {0, 0}, start = {0, 0}, end;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scale *= 2;
    end = {scale, scale};
    for (int i = 0; i < n * 2; i++)
    {
        scanf("%*c%1c", &s[i]);
        switch (s[i])
        {
        case 'R':
            start.row = (start.row + end.row) / 2;
            break;
        case 'D':

            start.column = (start.column + end.column) / 2;
            break;
        case 'L':
            end.row = (start.row + end.row) / 2;
            break;
        case 'U':
            end.column = (start.column + end.column) / 2;
            break;
        default:
            break;
        }
    }
    scanf("%d", &m);
    map[start.column][start.row] = m;
    for (int i = n * 2 - 1; i >= 0; i--)
    {
        switch (s[i])
        {
        case 'R':
            for (int j = start.column; j < end.column; j++)
            {
                for (int k = 0; k < end.row - start.row; k++)
                {
                    map[j][start.row * 2 - end.row + k] = (map[j][end.row - k - 1] * (-1) + 5) % 4;
                }
            }
            start.row += start.row - end.row;
            break;
        case 'D':
            for (int j = 0; j < end.column - start.column; j++)
            {
                for (int k = start.row; k < end.row; k++)
                {
                    map[start.column * 2 - end.column + j][k] = (map[end.column - j - 1][k] + 2) % 4;
                }
            }
            start.column += start.column - end.column;
            break;
        case 'L':
            for (int j = start.column; j < end.column; j++)
            {
                for (int k = 0; k < end.row - start.row; k++)
                {
                    map[j][end.row + k] = (map[j][end.row - k - 1] * (-1) + 5) % 4;
                }
            }
            end.row += end.row - start.row;
            break;
        case 'U':
            for (int j = 0; j < end.column - start.column; j++)
            {
                for (int k = start.row; k < end.row; k++)
                {
                    map[end.column + j][k] = (map[end.column - j - 1][k] + 2) % 4;
                }
            }
            end.column += end.column - start.column;
            break;
        default:
            break;
        }
        // printf("%d %c\n{%d,%d},{%d %d}\n", n * 2 - i, s[i], start.column, start.row, end.column, end.row);
    }
    for (int i = 0; i < scale; i++)
    {
        for (int j = 0; j < scale; j++)
            printf("%d ", map[i][j]);
        puts("");
    }
    return 0;
}