#include <bits/stdc++.h>
using namespace std;
char s[100002];
int main()
{
    int k, n;
    scanf("%d %d%*c", &k, &n);
    cin.getline(s, n + 1, '\n');
    k %= 26;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] + k > 'Z')
                s[i] -= 26;
            s[i] += k;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] + k > 'z')
                s[i] -= 26;
            s[i] += k;
        }
    }
    printf("%s",s);
}