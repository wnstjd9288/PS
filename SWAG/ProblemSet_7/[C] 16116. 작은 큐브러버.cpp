#include <bits/stdc++.h>
using namespace std;
int cube[80][30];
int check[60][60] = {
    0,
};
int visited[60] = {
    0,
};
int main()
{
    int r;
    for (int i = 0; i < 8; i++)
    {
        string s;
        getline(cin, s);
        int cnt = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if ('A' <= s[j] && s[j] <= 'Z')
            {
                int k;
                switch (s[j])
                {
                case 'B':
                    k = 0;
                    break;
                case 'G':
                    k = 1;
                    break;
                case 'O':
                    k = 2;
                    break;
                case 'R':
                    k = 3;
                    break;
                case 'W':
                    k = 4;
                    break;
                case 'Y':
                    k = 5;
                    break;
                }
                cube[i][cnt++] = k;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == j)
                    continue;
                check[cube[i][j]][cube[i][k]]++;
            }
        }
    }
    int cnt = 0;
    for (int line = 0; line < 6; line++)
    {
        vector<pair<int, pair<int, int>>> c1, c2;
        if (visited[line])
            continue;
        for (int i = 0; i < 6; i++)
        {
            int flag = 0;
            for (int j = 0; j < 6; j++)
            {
                if (i == j)
                    continue;
                if (!check[i][j])
                {
                    if (check[j][i] || flag)
                    {
                        printf("NO");
                        return 0;
                    }
                    flag = 1;
                }
                if (i == line && !check[i][j])
                {
                    r = j;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            int flag = 0;
            for (int j = 0; j < 3; j++)
            {
                if (cube[i][j] == line && j)
                {
                    flag = 1;
                    break;
                }
                if (cube[i][j] == r && j)
                {
                    flag = 2;
                    break;
                }
            }
            if (flag == 1)
                while (cube[i][0] != line)
                {
                    int temp = cube[i][0];
                    cube[i][0] = cube[i][1];
                    cube[i][1] = cube[i][2];
                    cube[i][2] = temp;
                }
            if (flag == 2)
            {
                while (cube[i][0] != r)
                {
                    int temp = cube[i][0];
                    cube[i][0] = cube[i][1];
                    cube[i][1] = cube[i][2];
                    cube[i][2] = temp;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (cube[i][0] == r)
                c2.push_back({cube[i][0], {cube[i][2], cube[i][1]}});
            else
                c1.push_back({cube[i][0], {cube[i][1], cube[i][2]}});
        }
        if (c1.size() != c2.size())
        {
            printf("NO");
            return 0;
        }
        for (int i = 0; i < c1.size(); i++)
            for (int j = 0; j < c2.size(); j++)
                if (c1[i].second.first == c2[j].second.first && c1[i].second.second == c2[j].second.second)
                    cnt++;
        check[line][r] = check[r][line] = -1;
        visited[line] = visited[r] = 1;
    }
    if (cnt == 12)
        printf("YES");
    else
        printf("NO");
    return 0;
}