#include <bits/stdc++.h>
int NGE[1000001];
int stack[1000001][2];
int main()
{
    int n, top = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        NGE[i] = -1;
        if (top == -1)
        {
            stack[++top][0] = a;
            stack[top][1] = i;
        }
        else
        {
            while (stack[top][0] < a && top >= 0)
            {
                NGE[stack[top][1]] = a;
                top--;
            }
            stack[++top][0] = a;
            stack[top][1] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", NGE[i]);
    }
}