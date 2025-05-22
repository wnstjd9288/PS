#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree;
int main()
{
    int n, n_copy;
    int in, ex;
    int in_cnt = 1, ex_cnt = 0;
    int exp = 1;
    int flag = 0;
    int result = -1;
    scanf("%d", &n);
    n_copy = sqrt(n);
    for (int i = n_copy; i >= 1; i--)
    {
        if (n % i == 0)
        {
            in = max(i, n / i);
            ex = min(i, n / i);
            break;
        }
    }
    tree.push_back(make_pair(-1, -1));
    for (int i = 1;; i++)
    {
        if (in_cnt < in)
        {
            if (!((ex + 1) / 2 <= exp && exp <= ex))
            {
                tree.push_back({i + 1, i + 2});
                in_cnt += 2;
                i++;
                exp++;
            }
            else
            {
                tree.push_back({i + 1, -1});
                in_cnt++;
            }
        }
        else
        {
            if (!flag)
            {
                flag = 1;
                exp = ex - exp;
            }
            if (exp > 0)
            {
                exp--;
                tree.push_back({i + 1, i + 2});
                ex_cnt += 2;
                i++;
            }
            else
            {
                tree.push_back({i + 1, -1});
                ex_cnt++;
                i++;
            }
            if (ex_cnt == ex)
                break;
        }
    }
    for (int i = 1; i < tree.size(); i++)
    {
        result = max(result, tree[i].first);
        result = max(result, tree[i].second);
    }
    printf("%d\n", result);
    for (int i = 1; i < tree.size(); i++)
    {
        printf("%d %d\n", i, tree[i].first);
        if (tree[i].second != -1)
            printf("%d %d\n", i, tree[i].second);
    }
}