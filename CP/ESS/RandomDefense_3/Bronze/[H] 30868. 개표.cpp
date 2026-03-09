#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n / 5; i++)
            printf("++++ ");
        for (int i = 0; i < n % 5; i++)
            printf("|");
        puts("");
    }
}