#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    int res = min(min(abs(h1 * 60 + m1 - h2 * 60 - m2), abs((h1 + 12) * 60 + m1 - h2 * 60 - m2)),abs(h1 * 60 + m1 - (h2+12) * 60 - m2));
    printf("%d", res*6);
}