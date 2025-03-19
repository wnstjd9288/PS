#include <stdio.h>
#define MOD 2019201997
int main()
{
    int n, k, cnt = 0;
    int mst = 0;
    scanf("%d %d", &n, &k);
    printf("%d", MOD - (k - 1) * 84 - n * 48);
}