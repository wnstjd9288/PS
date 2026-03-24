#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        if (k)
            pq.push(k);
        else
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
}