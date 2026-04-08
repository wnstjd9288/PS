#include <stdio.h>
#include <unordered_map>
using namespace std;
int arr[100001];
int main()
{
    int n;
    unordered_map<int, int> map;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        map[a] = 1;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (map[arr[i]] == 1)
            printf("1\n");
        else
            printf("0\n");
    }
}