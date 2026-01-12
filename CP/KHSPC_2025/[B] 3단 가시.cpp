#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        int x, flag = 0;
        long long int n, p[10001], startjump = 0;
        scanf("%lld", &n);
        scanf("%d",&x);
        for (int i = 0; i < x; i++)
            scanf("%lld", &p[i]);
        startjump = p[0];
        for (int i = 1; i < x; i++)
        {
            long long int endjump = startjump + 3LL;
            if (p[i] < endjump)
                continue;
            else if (p[i] == endjump)
            {
                flag = 1;
                break;
            }
            else if (p[i] > endjump)
            {
                startjump = p[i];
            }
        }
        cout << (flag ? "IMPOSSIBLE\n" : "POSSIBLE\n");
    }
}