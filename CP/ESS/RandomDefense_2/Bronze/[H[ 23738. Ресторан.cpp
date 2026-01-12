#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[101];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
        case 'B':
            printf("v");
            break;
        case 'E':
            printf("ye");
            break;
        case 'H':
            printf("n");
            break;
        case 'P':
            printf("r");
            break;
        case 'C':
            printf("s");
            break;
        case 'Y':
            printf("u");
            break;
        case 'X':
            printf("h");
            break;
        default:
            printf("%c", s[i] + 32);
        }
    }
    return 0;
}