#include <bits/stdc++.h>
using namespace std;
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
set<pair<int, int>, cmp> s;
int main()
{
    string str, num;
    int n, l[11] = {
               0,
           };
    vector<string> m;
    getline(cin, str);
    scanf("%d", &n);

    stringstream ss(str);
    while (getline(ss, num, ' '))
    {
        m.push_back(num);
    }
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            l[i] *= 10;
            l[i] += m[i][j] - 48;
        }
        //printf("strlen: %d, l[i]: %d\n", m[i].size(),l[i]);
    }
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = i + 1; j < m.size(); j++)
        {
            if (l[i] + l[j] == n)
            {
                if (s.find(make_pair(l[i], l[j])) == s.end() && s.find(make_pair(l[j], l[i])) == s.end())
                {
                    if (l[i] > l[j])
                        s.insert(make_pair(l[j], l[i]));
                    else
                        s.insert(make_pair(l[i], l[j]));
                }
            }
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        printf("%d %d\n", (*it).first, (*it).second);
    }
    printf("%d", s.size());
}