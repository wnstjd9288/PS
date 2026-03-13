#include <bits/stdc++.h>
using namespace std;
vector<char> arr;
int l, c;
void pw(int now, int mo, int ja, string str)
{
    if (mo + ja == l)
    {
        if (mo >= 1 && ja >= 2)
            cout << str << '\n';
        return;
    }
    if (now == c)
        return;
    if (arr[now] == 'a' || arr[now] == 'e' || arr[now] == 'i' || arr[now] == 'o' || arr[now] == 'u')
    {
        pw(now + 1, mo + 1, ja, str + arr[now]);
    }
    else
    {
        pw(now + 1, mo, ja + 1, str + arr[now]);
    }
    pw(now + 1, mo, ja, str);
}
int main()
{
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++)
    {
        char a;
        scanf("%*c%c", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    pw(0, 0, 0, "");
}