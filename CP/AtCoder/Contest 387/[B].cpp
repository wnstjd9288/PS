#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (n != i * j)
                sum += i * j;
        }
    }
    printf("%d", sum);
}