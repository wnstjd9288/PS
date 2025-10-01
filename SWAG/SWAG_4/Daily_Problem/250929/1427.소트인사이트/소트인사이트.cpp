#include <bits/stdc++.h>
int cmp(const void *a, const void *b)
{
    return *(char *)b - *(char *)a;
}
int main()
{
    char s[11];
    scanf("%s", s);
    qsort(s, strlen(s), sizeof(char), cmp);
    printf("%s", s);
    return 0;
}