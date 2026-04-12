#include <bits/stdc++.h>
using namespace std;
stack<int> down, up;
int arr[100001];
int main()
{
    int n;
    int res = -1;
    unordered_map<int, bool> downmap;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        res = max(res, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            if (down.empty())
            {
                down.push(arr[i]);
                downmap[arr[i]] = true;
            }
            else
            {
                if (arr[i] < down.top())
                {
                    down.push(arr[i]);
                    downmap[arr[i]] = true;
                }
                if (arr[i] > down.top())
                {
                    while (!down.empty() && arr[i] >= down.top())
                    {
                        downmap[down.top()] = false;
                        down.pop();
                    }
                    down.push(arr[i]);
                    downmap[arr[i]] = true;
                }
            }
        }
        else
        {
            int build = 1;
            if (i == n - 1 || !arr[i + 1])
            {
                if (down.empty())
                {
                    down.push(build);
                    downmap[build] = true;
                    res = max(res, build);
                }
                else
                {
                    while (1)
                    {
                        if (down.empty() || build < down.top())
                        {
                            down.push(build);
                            downmap[build] = true;
                            res = max(res, build);
                            break;
                        }
                        else if (build == down.top())
                        {
                            build++;
                            downmap[down.top()] = false;
                            down.pop();
                        }
                    }
                }
            }
            else
            {

                int s = i + 1, e = n;
                for (int j = s; j < n; j++)
                {
                    if (!arr[j])
                    {
                        e = j;
                        break;
                    }
                }
                for (int j = e - 1; j >= s; j--)
                {
                    if (arr[j])
                    {
                        if (up.empty())
                            up.push(arr[j]);
                        else
                        {
                            if (arr[j] < up.top())
                                up.push(arr[j]);
                            if (arr[j] > up.top())
                            {
                                while (!up.empty() && arr[j] >= up.top())
                                    up.pop();
                                up.push(arr[j]);
                            }
                        }
                    }
                }
                unordered_map<int, bool> m;
                while (!up.empty())
                {
                    m[up.top()] = true;
                    up.pop();
                }

                if (down.empty())
                {
                    while (m[build])
                        build++;
                    down.push(build);
                    downmap[build] = true;
                    res = max(res, build);
                }
                else
                {
                    unordered_map<int, bool> same;
                    int maxsame = 0;
                    for (auto pair : m)
                    {
                        if (pair.second && downmap[pair.first])
                        {
                            same[pair.first] = true;
                            maxsame = max(pair.first, maxsame);
                        }
                    }
                    build = maxsame + 1;
                    while (1)
                    {
                        bool conflict = false;
                        if (downmap[build] || m[build])
                            conflict = true;
                        if (!conflict)
                            break;
                        if (!down.empty() && down.top() == build)
                        {
                            downmap[down.top()] = false;
                            down.pop();
                        }
                        build++;
                    }
                    while (!down.empty() && down.top() <= build)
                    {
                        downmap[down.top()] = false;
                        down.pop();
                    }
                    down.push(build);
                    downmap[build] = true;
                    res = max(res, build);
                }
            }
        }
    }
    printf("%d", res);
}