#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int news[1000001];
int num[1000001];
int main()
{
    int n;
    int prev = -1;
    int idx = 1;
    int cnt = 1;
    long long int res=0;
    scanf("%s", s);
    n = strlen(s);
    news[0] = prev = s[0] - '0';
    for (int i = 1; i < n; i++)
    {
        if (s[i] - '0' != prev)
        {
            num[idx-1] = cnt;
            news[idx++] = s[i] - '0';
            cnt = 1;
            prev = s[i] - '0';
        }
        else
            cnt++;
    }
    num[idx-1] = cnt;
    for (int i = 0; i < idx-1; i++)
    {
        if(news[i]+1==news[i+1])res+=min(num[i],num[i+1]);
    }
    printf("%lld",res);
}