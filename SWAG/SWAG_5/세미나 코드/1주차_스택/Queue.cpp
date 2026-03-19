#include <stdio.h>

int queue[100];
int head = -1, tail = -1;

int is_empty()
{
    if (head >= tail)
        return 1;
    else
        return 0;
}

void push(int data)
{
    queue[++tail] = data;
}
int pop()
{
    if (is_empty())
        return __INT_MAX__;
    int data = queue[++head];
    return data;
}

int main()
{
    for (int i = 1; i <= 5; i++)
        push(i);
    for (int i = 0; i < 5; i++)
        printf("%d ", pop());
}

