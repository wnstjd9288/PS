#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    b /= 2;
    printf("%d", min(min(a, b), c));
}