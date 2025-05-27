#include <bits/stdc++.h>
using namespace std;
int n;
void print_sound(int a)
{
    a = (a + n) % 12;
    switch (a)
    {
    case 0:
        printf("A ");
        break;
    case 1:
        printf("A# ");
        break;
    case 2:
        printf("B ");
        break;
    case 3:
        printf("C ");
        break;
    case 4:
        printf("C# ");
        break;
    case 5:
        printf("D ");
        break;
    case 6:
        printf("D# ");
        break;
    case 7:
        printf("E ");
        break;
    case 8:
        printf("F ");
        break;
    case 9:
        printf("F# ");
        break;
    case 10:
        printf("G ");
        break;
    case 11:
        printf("G# ");
        break;
    }
}
int main()
{
    while (1)
    {
        char s[10001];
        scanf("%[^\n]s%*c", s);
        if (s[0] == '*')
            break;
        scanf("%d%*c", &n);
        n %= 12;
        if (n < 0)
            n += 12;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            switch (s[i])
            {
            case 'A':
                if (s[i + 1] == '#')
                    print_sound(1);
                else if (s[i + 1] == 'b')
                    print_sound(11);
                else
                    print_sound(0);
                break;
            case 'B':
                if (s[i + 1] == '#')
                    print_sound(3);
                else if (s[i + 1] == 'b')
                    print_sound(1);
                else
                    print_sound(2);
                break;
            case 'C':
                if (s[i + 1] == '#')
                    print_sound(4);
                else if (s[i + 1] == 'b')
                    print_sound(2);
                else
                    print_sound(3);
                break;
            case 'D':
                if (s[i + 1] == '#')
                    print_sound(6);
                else if (s[i + 1] == 'b')
                    print_sound(4);
                else
                    print_sound(5);
                break;
            case 'E':
                if (s[i + 1] == '#')
                    print_sound(8);
                else if (s[i + 1] == 'b')
                    print_sound(6);
                else
                    print_sound(7);
                break;
            case 'F':
                if (s[i + 1] == '#')
                    print_sound(9);
                else if (s[i + 1] == 'b')
                    print_sound(7);
                else
                    print_sound(8);
                break;
            case 'G':
                if (s[i + 1] == '#')
                    print_sound(11);
                else if (s[i + 1] == 'b')
                    print_sound(9);
                else
                    print_sound(10);
                break;
            }
        }
        puts("");
    }
}