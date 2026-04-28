#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 5 != 1)
        printf("No");
    else
    {
        deque<int> dq;
        printf("Yes\n");
        dq.push_back(0);
        dq.push_back(2);
        for (int i = 0; i < n / 5 * 2; i++)
        {
            dq.push_back(i % 2 ? 2 : 1);
            dq.push_front(i % 2 ? 0 : 1);
        }
        for (int i = 0; i < n / 5 - 1; i++)
        {
            dq.push_back(i % 2 ? 2 : 0);
        }
        while(!dq.empty()){
            printf("%d ",dq.front());
            dq.pop_front();
        }
    }
}