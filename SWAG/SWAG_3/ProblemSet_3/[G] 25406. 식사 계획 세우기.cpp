#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int value;
    int start;
    int end;
    int index;
} grid;

vector<pair<int, int>> rest;
vector<grid> rest_list;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        if (a.second < b.second)
            return true;
        else
            return false;
    else
        return false;
}
struct Compare_1
{
    bool operator()(const grid &a, const grid &b) const
    {
        if (a.end - a.start == b.end - b.start)
            return a.index < b.index;
        else
            return a.end - a.start > b.end - b.start;
    }
};
struct Compare_2
{
    bool operator()(const grid &a, const grid &b) const
    {
        return a.index < b.index;
    }
};
int main()
{
    int n;
    bool flag = true;
    set<grid, Compare_1> count;
    set<grid, Compare_2> idx;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        rest.push_back(make_pair(a, i));
    }
    sort(rest.begin(), rest.end(), cmp);
    int start = 0;
    int var = rest[0].second;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            rest_list.push_back({rest[i - 1].first, start, n, var});
            break;
        }
        if (rest[i].first != rest[i - 1].first)
        {
            rest_list.push_back({rest[i - 1].first, start, i, var});
            start = i;
            var = rest[i].second;
        }
    }
    // for (int i = 0; i < rest.size(); i++)
    // printf("rest %d,%d\n", rest[i].first, rest[i].second);
    for (int i = 0; i < rest_list.size(); i++)
    {
        count.insert(rest_list[i]);
        idx.insert(rest_list[i]);
        // printf("rest_list %d, %d %d %d\n", rest_list[i].value, rest_list[i].start, rest_list[i].end, rest_list[i].index);
    }
    int prev = -1;
    while (n)
    {
        /*printf("n:%d\n", n);
        for (auto iter = count.begin(); iter != count.end(); iter++)
        {
            printf("count %d, %d %d %d\n", (*iter).value, (*iter).start, (*iter).end, (*iter).index);
        }
        for (auto iter = idx.begin(); iter != idx.end(); iter++)
        {
            printf("idx %d, %d %d %d\n", (*iter).value, (*iter).start, (*iter).end, (*iter).index);
        }*/
        auto count_it = count.begin();
        if ((*count_it).end - (*count_it).start < (n + 1) / 2 || (*count_it).end - (*count_it).start == (n + 1) / 2 && n % 2 == 0)
        {
            auto idx_it = idx.begin();
            while ((*idx_it).value == prev)
                idx_it++;
            printf("%d ", (*idx_it).index);
            count.erase(*count.find((*idx_it)));
            auto temp = idx.extract((*idx_it));
            temp.value().start++;
            temp.value().index = rest[temp.value().start].second;
            if (temp.value().start != temp.value().end)
            {
                count.insert(temp.value());
                idx.insert(temp.value());
            }
            prev = temp.value().value;
        }
        else if ((*count_it).end - (*count_it).start == (n + 1) / 2 && n % 2 == 1)
        {
            printf("%d ", (*count_it).index);
            auto temp = count.extract((*count_it));
            idx.erase(*idx.find((*count_it)));
            temp.value().start++;
            temp.value().index = rest[temp.value().start].second;
            if (temp.value().start != temp.value().end)
            {
                count.insert(temp.value());
                idx.insert(temp.value());
            }
            prev = temp.value().value;
        }
        else
        {
            printf("-1");
            break;
        }
        n--;
    }
}