#include <bits/stdc++.h>
int cod[501][501];
int xx[6] = {0, 1, 1, 0, -1, -1}, yy[6] = {1, 1, -1, -1, -1, 1};
int n;
long long int cnt = 0;
void ant(int count, int dir, int x, int y)
{
    if (cod[x][y] == 1)
    {
        if (count == n)
            cnt++;
        return;
    }
    if (count == n)
        return;
    cod[x][y] = 1;
    int nd[2] = {(dir + 1) % 6, (dir + 5) % 6};
    for (int i = 0; i < 2; i++)
        ant(count + 1, nd[i], x + xx[nd[i]], y + yy[nd[i]]);
    cod[x][y] = 0;
}
int main()
{
    scanf("%d", &n);
    cod[255][255] = 1;
    ant(0, 0, 255, 256);
    printf("%lld", cnt);
}