#include <bits/stdc++.h>
int prime[5000001];
int sum[5000001];
int main()
{
    for (int i = 2; i <= sqrt(5000000); i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= 5000000; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 1; i <= 5000000; i++)
    {
        if (!prime[i])
            sum[i]++;
        sum[i] += sum[i - 1];
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}