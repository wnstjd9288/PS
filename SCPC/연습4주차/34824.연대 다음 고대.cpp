#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.compare("yonsei") == 0 && !flag)
            flag = 1;
        else if (s.compare("korea") == 0 && !flag)
            flag = 2;
    }
    if (flag == 1)
        printf("Yonsei Won!");
    else
        printf("Yonsei Lost...");
}