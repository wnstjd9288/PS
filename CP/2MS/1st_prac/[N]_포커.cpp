#include <bits/stdc++.h>
int trump[4][14]; // S D H C
char type[10], number[2];
void input_trump(int a)
{
    if ('2' <= number[0] && number[0] <= '9')
        trump[a][number[0] - '0'] = 1;
    else if (number[0] == '1')
        trump[a][10] = 1;
    else if (number[0] == 'A')
        trump[a][1] = 1;
    else if (number[0] == 'J')
        trump[a][11] = 1;
    else if (number[0] == 'Q')
        trump[a][12] = 1;
    else if (number[0] == 'K')
        trump[a][13] = 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", type, number);
        switch (type[0])
        {
        case 'S':
            input_trump(0);
            break;
        case 'D':
            input_trump(1);
            break;
        case 'H':
            input_trump(2);
            break;
        case 'C':
            input_trump(3);
            break;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            printf("%d ",trump[i][j]);
        }puts("");
    }x`
}