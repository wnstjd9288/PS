#include <bits/stdc++.h>
int stack[100001];
int check[200001] = {
    0,
};
int arr[100001];
int top = -1;
int main()
{
    int n, now = 1, cnt = 0;
    bool flag = true;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {

        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n && flag; i++)
    {
        int a = arr[i];
        if (now <= a)
        {
            for (int j = now; j <= a; j++)
            {
                stack[++top] = j;
                check[cnt++] = 1;
            }
            top--;
            check[cnt++] = -1;
            now = a + 1;
        }
        else
        {
            if (stack[top] != a)
                flag = false;
            else
            {
                top--;
                check[cnt++] = -1;
            }
        }
    }
    if (flag)
        for (int i = 0; i < cnt; i++)
            printf("%c\n", check[i] == 1 ? '+' : '-');
    else
        printf("NO");
}