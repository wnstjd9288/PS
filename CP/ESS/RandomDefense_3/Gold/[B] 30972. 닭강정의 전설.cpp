#include <bits/stdc++.h>
using namespace std;
int m[5002][5002] = {
    0,
};
int Box(int r1, int c1, int r2, int c2)
{
    return m[r2][c2] - m[r2][c1 - 1] - m[r1 - 1][c2] + m[r1 - 1][c1 - 1];
}
int main()
{
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
            m[i][j] += m[i][j - 1];
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            m[i][j] += m[i - 1][j];

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

        printf("%d\n", 2 * Box(r1 + 1, c1 + 1, r2 - 1, c2 - 1) - Box(r1, c1, r2, c2));
    }
}