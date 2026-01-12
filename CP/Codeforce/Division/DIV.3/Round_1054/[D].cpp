#include <bits/stdc++.h>
using namespace std;
char s[200001];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        vector<int> a, b;
        long long int asum = LONG_LONG_MAX, bsum = LONG_LONG_MAX;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a.push_back(i);
            else
                b.push_back(i);
        }
        if (a.size())
        {
            asum = 0;
            int ai = a.size() / 2;
            int amid = a[ai];
            for (int i = 0; i < a.size(); i++)
            {
                asum += abs(a[i] - abs(amid - (ai - i)));
            }
        }
        if (b.size())
        {
            bsum = 0;
            int bi = b.size() / 2;
            int bmid = b[bi];
            for (int i = 0; i < b.size(); i++)
            {
                bsum += abs(b[i] - abs(bmid - (bi - i)));
            }
        }
        printf("%lld\n", min(asum, bsum));
    }
}