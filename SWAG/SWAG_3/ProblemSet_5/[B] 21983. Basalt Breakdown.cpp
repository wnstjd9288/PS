#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    double result;
    scanf("%lld", &n);
    result = n;
    result = sqrt((n * 2) / (3 * sqrt(3))) * 6;
    printf("%.8f\n", result);
}