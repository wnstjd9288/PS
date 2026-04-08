#include <bits/stdc++.h>
int arr[5];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr[a - 1] = 1;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += arr[i];
    if(sum!=5)printf("YES");
    else printf("NO");
}