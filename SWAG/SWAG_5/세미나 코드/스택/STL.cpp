#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>

int main()
{
    std::stack<int> s;
    std::queue<int> q;
    std::deque<int> dq;

    s.push(1);
    s.push(2);
    s.push(3);
    printf("%d\n", s.top());
    s.pop();

    q.push(1);
    q.push(2);
    q.push(3);
    printf("%d %d\n", q.front(), q.back());
    q.pop();

    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    printf("%d %d\n", dq.front(), dq.back());
    dq.pop_back();
    dq.pop_front();
}

