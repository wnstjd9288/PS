#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b;
    while (scanf("%d", &b) && b != 0)
    {
        vector<int> result;
        char p[1001], m[10];
        scanf("%s %s", p, m);
        int m_n = 0, p_n = 0;
        for (int i = 0; i < strlen(m); i++)
        {
            m_n = m_n * b + (m[i] - 48);
        }
        for (int i = 0; i < strlen(p); i++)
        {
            p_n = (p_n * b + (p[i] - 48)) % m_n;
        }
        while (p_n)
        {
            result.push_back(p_n % b);
            p_n /= b;
        }
        if (result.size())
            for (int i = result.size() - 1; i >= 0; i--)
                printf("%d", result[i]);
        else
            printf("0");
        puts("");
    }
}