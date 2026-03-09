#include <bits/stdc++.h>
using namespace std;
char s[61], t[61];
vector<char> a, b;
void Solve()
{
}
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        a.push_back(s[i]);
        b.push_back(t[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<char>());
}