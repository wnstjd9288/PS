#include <stdio.h>
#define MAX_SIZE 100

int deque[MAX_SIZE];
int head = 0, tail = 0;

void push_front(int data)
{
    head = (head - 1 + MAX_SIZE) % MAX_SIZE;
    deque[head] = data;
}
void push_back(int data)
{
    deque[tail] = data;
    tail = (tail + 1) % MAX_SIZE;
}
int pop_front()
{
    int data = deque[head];
    head = (head + 1) % MAX_SIZE;
    return data;
}
int pop_back()
{
    tail = (tail - 1 + MAX_SIZE) % MAX_SIZE;
    int data = deque[tail];
    return data;
}

int main()
{
    push_back(1);
    push_back(2);
    push_front(3);
    push_back(4);
    push_front(5);

    printf("%d ", pop_back());
    printf("%d ", pop_front());
    printf("%d ", pop_front());
    printf("%d ", pop_front());
    printf("%d ", pop_back());
}

