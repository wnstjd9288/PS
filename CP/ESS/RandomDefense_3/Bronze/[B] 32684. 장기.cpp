#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;
    int score[6] = {13, 7, 5, 3, 3, 2};
    for (int i = 0; i < 6; i++)
    {
        int a;
        scanf("%d", &a);
        res += score[i] * a;
    }
    for (int i = 0; i < 6; i++)
    {
        int a;
        scanf("%d", &a);
        res -= score[i] * a;
    }
    if (res > 1)
        printf("cocjr0208");
    else
        printf("ekwoo");
}