#include <bits/stdc++.h>
using namespace std;
struct container
{
    int p;
    int w;
};
int p_rank[101];
int main()
{
    int n, m;
    stack<container> mainStack, subStack;
    queue<container> q;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        container c;
        scanf("%d%d", &c.p, &c.w);
        p_rank[c.p]++;
        q.push(c);
    }
    int res = 0;
    while (m != 0)
    {

        container c = q.front();
        if (q.front().p == m)
        {
            if (mainStack.empty() || mainStack.top().p > c.p || mainStack.top().p == c.p && mainStack.top().w >= c.w)
            {
                mainStack.push(c);
                res += c.w;
            }
            else
            {
                while (!mainStack.empty() && mainStack.top().w < c.w && mainStack.top().p == c.p)
                {
                    subStack.push(mainStack.top());
                    res += mainStack.top().w;
                    mainStack.pop();
                }
                mainStack.push(c);
                res += c.w;
                while (!subStack.empty())
                {
                    mainStack.push(subStack.top());
                    res += subStack.top().w;
                    subStack.pop();
                }
            }
            p_rank[m]--;
            if (!p_rank[m])
                m--;
        }
        else
        {
            q.push(c);
            res += c.w;
        }
        q.pop();
    }
    printf("%d", res);
}