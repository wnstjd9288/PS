#include <stdio.h>
int stack[100];
int top = -1;

int is_empty(){
    if(top>=0) return 0;
    else return 1;
}

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    if(is_empty()) return __INT_MAX__;
    int data = stack[top--];
    return data;
}

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", pop());
    }
}

