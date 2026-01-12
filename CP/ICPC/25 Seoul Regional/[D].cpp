#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int pos, width;
} book;
book b[100011];
vector<int> thick;
int main()
{
    int n, l, k, p;
    bool thicktarget = false;
    scanf("%d %d", &n, &l);
    int empty = l;
    int moveable = l;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i].pos);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i].width);
        empty -= b[i].width;
    }
    scanf("%d %d", &k, &p);
    if (b[k].width + p > l)
    {
        printf("NO");
        return 0;
    }
    if (b[k].pos == p)
    {
        printf("YES");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i].width > empty)
        {
            if (i == k)
                thicktarget = true;
            thick.push_back(i);
            moveable -= b[i].width;
        }
    }
    if (thicktarget)
    {
        int now = 0;
        for (auto target : thick)
        {
            if (target == k)
            {
                if (now + moveable >= p)
                    printf("YES");
                else
                    printf("NO");
                return 0;
            }
            else
                now += b[target].width;
            if (now > p)
            {
                printf("NO");
                return 0;
            }
        }
    }
    else
    {
        int now = 0;
        for (auto thickbook : thick)
        {
            now += b[thickbook].width;
            if (now > p)
            {
                now -= b[thickbook].width;
                if (now + moveable >= p + b[k].width)
                    printf("YES");
                else
                    printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}