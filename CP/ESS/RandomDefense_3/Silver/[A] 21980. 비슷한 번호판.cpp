#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d", &test);
    for (int t = 0; t < test; t++)
    {
        map<string, int> m;
        int n, k, res = 0;
        scanf("%d%d%*c", &n, &k);
        for (int i = 0; i < n; i++)
        {
            char s[21];
            int upper = 0;
            string str;
            scanf("%s", s);
            str = s;
            for (int j = 0; j < k; j++)
            {
                if (str[j] <= 'Z')
                {
                    str[j] += 32;
                    upper++;
                }
            }
            sort(str.begin(), str.end());
            str += to_string(upper);
            m[str]++;
        }
        for (auto p : m)
        {
            int cnt = p.second;
            res += cnt * (cnt - 1) / 2;
        }
        printf("%d\n", res);
    }
}