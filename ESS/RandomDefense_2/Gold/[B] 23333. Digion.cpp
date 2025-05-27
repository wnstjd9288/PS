#include <bits/stdc++.h>
using namespace std;

char s[61];

string next_digion(string s)
{
    int n = s.size();

    // Step 1: 오른쪽에서부터 (를 찾는다
    int depth = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == ')')
            depth++;
        else
        {
            depth--;

            if (depth > 0)
            {
                // Step 2: s[i] = ')'로 바꾸기
                string result = s;
                result[i] = ')';

                // Step 3: 남은 부분에서 (, )를 몇 개 쓸 수 있는지 계산
                int open_used = count(result.begin(), result.begin() + i + 1, '(');
                int close_used = count(result.begin(), result.begin() + i + 1, ')');
                int open_left = (n / 2) - open_used;
                int close_left = (n / 2) - close_used;

                // Step 4: 사전순 최소 괄호열로 이어붙이기
                return result.substr(0, i + 1) +
                       string(open_left, '(') +
                       string(close_left, ')');
            }
        }
    }

    return "-1";
}

int main()
{
    char s[61];
    int flag = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        if (s[i] != '(')
            flag = 1;
    }
    if (flag)
    {

        string input(s);

        string next = next_digion(input);
        printf("%s", next.c_str());
    }
    else
    {
        for (int i = 0; i <= strlen(s) / 2; i++)
        {
            printf("()");
        }
    }
    return 0;
}
