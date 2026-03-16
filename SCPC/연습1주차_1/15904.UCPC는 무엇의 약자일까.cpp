#include <bits/stdc++.h>
char s[1001];
char arr[4] = {'U', 'C', 'P', 'C'};
int main()
{
    scanf("%[^\n]s", s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == arr[cnt])
            cnt++;
        if (cnt == 4)
        {
            printf("I love UCPC");
            return 0;
        }
    }
    printf("I hate UCPC");
}