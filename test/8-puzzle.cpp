#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
struct cmp
{
    bool operator()(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b)
    {
        if (a.second.second == b.second.second)
            return a.first > b.first;
        return a.second.second > b.second.second;
    }
};
unordered_map<string, pair<string, int>> visited;
priority_queue<pair<int, pair<string, int>>, vector<pair<int, pair<string, int>>>, cmp> pq;
stack<string> r;
int hn(string s)
{
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s.at(i * 3 + j) != '0')
                res += abs((s.at(i * 3 + j) - '0' - 1) / 3 - i) + abs((s.at(i * 3 + j) - '0' - 1) % 3 - j);
            // printf("{%d,%d} %c,%d: %d\n", i,j,s.at(i * 3 + j), i * 3 + j, res);
        }
    }
    return res;
}
pair<int, int> find_zero(string s)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (s.at(i * 3 + j) == '0')
                return {i, j};
        }
    }
    return {-1, -1};
}
void make_result(string now)
{

    while (now.at(0) != '9')
    {
        r.push(now);
        now = visited[now].first;
    }
}
void show_result()
{
    while (!r.empty())
    {
        pair<int, int> zero = find_zero(r.top());
        printf("{%d,%d}\n", zero.first, zero.second);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                printf("%c ", r.top().at(i * 3 + j));
            puts("");
        }
        printf("\n");
        // printf("%s\n", r.top().c_str());
        r.pop();
    }
}
int main()
{
    pair<int, int> xy[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    string result = "123456780";
    string s = "804715263";
    int is_can = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (s[i] == '0' || s[j] == '0')
                continue;
            if (s[i] > s[j])
                is_can++;
        }
    }
    if (is_can % 2)
    {
        printf("can't find for Inversion count.\n");
        return 0;
    }

    pq.push({1, {s, 1 + hn(s)}});
    visited[s] = {"9", 1};

    while (!pq.empty())
    {
        pair<int, pair<string, int>> now = pq.top();
        pq.pop();
        if (!now.second.first.compare(result))
        {
            make_result(result);
            show_result();
            return 0;
        }
        pair<int, int> zero = find_zero(now.second.first);
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {zero.first + xy[i].first, zero.second + xy[i].second};
            if (next.first < 0 || next.first > 2 || next.second < 0 || next.second > 2)
                continue;
            string next_string = now.second.first;
            next_string[zero.first * 3 + zero.second] = next_string[next.first * 3 + next.second];
            next_string[next.first * 3 + next.second] = '0';
            if (visited[next_string].second)
            {
                if (visited[next_string].second > now.first + 1)
                {
                    pq.push({now.first + 1, {next_string, now.first + 1 + hn(next_string)}});
                    visited[next_string] = {now.second.first, now.first + 1};
                }
            }
            else
            {
                pq.push({now.first + 1, {next_string, now.first + 1 + hn(next_string)}});
                visited[next_string] = {now.second.first, now.first + 1};
            }
        }
    }
    printf("can't find\n");
}
