#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> m;
vector<pair<int, int>> m_ori, range;
pair<int, int> child[200001];
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, h;
        scanf("%d%d", &a, &h);
        m.push_back({i, {a, h}});
        m_ori.push_back({a, h});
        range.push_back({-2e9 - 1, 2e9 + 1});
    }
    sort(m.begin(), m.end(), cmp);
    if (m[0].second.second != 1)
    {
        printf("-1");
        return 0;
    }
    deque<int> deq;
    deq.push_back(0);
    for (int i = 1; i < n; i++)
    {
        while (1)
        {
            if (deq.empty())
            {
                printf("-1");
                return 0;
            }
            int top = deq.front();
            if (m[top].second.second == m[i].second.second)
            {
                printf("-1");
                return 0;
            }
            else if (m[i].second.second - m[top].second.second > 1)
                deq.pop_front();
            else if (m[i].second.second - m[top].second.second == 1)
            {
                if (range[top].first < m[i].second.first && m[i].second.first < m[top].second.first && child[top].first == 0)
                {
                    child[top].first = i;
                    deq.push_back(i);
                    range[i].first = range[top].first;
                    range[i].second = m[top].second.first;
                    break;
                }
                else if (m[top].second.first < m[i].second.first && m[i].second.first < range[top].second && child[top].second == 0)
                {
                    child[top].second = i;
                    deq.push_back(i);
                    range[i].first = m[top].second.first;
                    range[i].second = range[top].second;
                    deq.pop_front();
                    break;
                }
                else
                {
                    deq.pop_front();
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int s = 0, e = n - 1, mid;
        while (s <= e)
        {
            mid = (s + e) / 2;
            int m_a = m[mid].second.first, m_h = m[mid].second.second;
            if (m[mid].second.second == m_ori[i - 1].second)
            {
                if (m[mid].second.first == m_ori[i - 1].first)
                {
                    break;
                }
                else if (m[mid].second.first > m_ori[i - 1].first)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if (m[mid].second.second > m_ori[i - 1].second)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        printf("%d %d\n", child[mid].first ? m[child[mid].first].first : -1, child[mid].second ? m[child[mid].second].first : -1);
    }
}