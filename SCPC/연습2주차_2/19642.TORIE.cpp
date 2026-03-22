#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> graph;
vector<string> strlist;
unordered_map<string, int> m;
int len;
int TORIE(string str, int now, int depth, int parent)
{
    string s;
    for (int i = now; i < len; i++)
    {
        if (str[i] == '[')
        {
            i = TORIE(str, now + 1, depth + 1, m[s]);
            continue;
        }
        if (str[i] == ']')
        {
            return i;
        }
        s += str[i];
    }
}
int main()
{
    string str;
    cin >> str;
    len = str.size();
    string s = "";
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '[')
        {
            strlist.push_back(s);
            m[s] = strlist.size();
            s = "";
            continue;
        }
        if (str[i] == ']')
            continue;
        s += str[i];
    }
    TORIE(str, 0, 1, -1);
}