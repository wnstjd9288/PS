#include <bits/stdc++.h>
char s[101][101];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%*c");
        for (int j = m - 1; j >= 0; j--)
        {
            scanf("%1c", &s[j][i]);
            switch (s[j][i])
            {
            case 45:
                s[j][i] = 124;
                break;
            case 124:
                s[j][i] = 45;
                break;
            case 47:
                s[j][i] = 92;
                break;
            case 92:
                s[j][i] = 47;
                break;
            case 94:
                s[j][i] = 60;
                break;
            case 60:
                s[j][i] = 118;
                break;
            case 118:
                s[j][i] = 62;
                break;
            case 62:
                s[j][i] = 94;
                break;
            default:
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%c",s[i][j]);
        }puts("");
    }
}