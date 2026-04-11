#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    queue<int> q;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        q.push(a);
    }
    int now = 1;
    while (!q.empty())
    {
        if (!q.empty() && now == q.front())
        {
            now++;
            q.pop();
            continue;
        }
        if (!s.empty() && now == s.top())
        {
            now++;
            s.pop();
            continue;
        }
        if (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        else
        {
            printf("Sad");
            return 0;
        }
    }
    while (!s.empty())
    {
        if (s.top() == now)
        {
            s.pop();
            now++;
        }
        else
        {
            printf("Sad");
            return 0;
        }
    }
    printf("Nice");
}