#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> map;
unordered_map<char, bool> exist;
char s[2001], t[2001];
bool Solve(int slen, int tlen)
{
    for (int i = 0; i < tlen; i++)
        if ('a' <= t[i] && t[i] <= 'z' && !exist[t[i]])
            return false;
    for (int i = 0; i <= tlen; i++)
    {
        if (s[i] != t[i])
        {
            
        }
    }
}
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int slen = strlen(s);
    int tlen = strlen(t);
    for (int i = 0; i < slen; i++)
        exist[s[i]] = true;
    return 0;
}