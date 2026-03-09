#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    vector<int> n(10000);
    for (int i = 0; i < 10000; i++)
    {
        n[i]=i+1;
    }
    random_shuffle(n.begin(), n.end());
    for (int i = 0; i < 10000; i++)
    {
        int ans;
        printf("? A %d\n", n[i]);
        fflush(stdout);
        scanf("%d%*c", &ans);
        if (ans)
        {
            ans = 0;
            for (int j = 0; j < 10000; j++)
            {
                printf("? B %d\n", n[j]);
                fflush(stdout);
                scanf("%d%*c", &ans);
                if (ans)
                {
                    printf("! %d", n[i] + n[j]);
                    return 0;
                }
            }
        }
    }
}