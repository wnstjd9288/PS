#include <bits/stdc++.h>
using namespace std;

int main()
{

    char s[33];
    int res;
    scanf("%s", s);
    res = strlen(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ':')
            res++;
        if (s[i] == '_')
            res += 5;
    }
    printf("%d", res);
}