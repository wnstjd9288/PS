#include <bits/stdc++.h>
char s[200001];
int main()
{
    int n;
    int res = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n - 1; i++)
    {
        switch (s[i])
        {
        case '[':
            res++;
            break;
        case ']':
            if (s[i + 1] != '[')
                res++;
            break;
        case '5':
            if (s[i + 1] == '5')
                res += 2;
            else
                res++;
            break;
        case '2':
            if (s[i + 1] == '2')
                res += 2;
            else
                res++;
            break;
        }
    }
    printf("%d", res);
}