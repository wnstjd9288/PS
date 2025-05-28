#include <bits/stdc++.h>
using namespace std;
int n;
void roll(int A[][11])
{
    int arr[11][11];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[n - 1 - j][i - j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            A[i][j] = arr[i][j];
        }
    }
}
void reverse(int A[][11])
{
    int arr[11][11];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[i][i - j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            A[i][j] = arr[i][j];
        }
    }
}
int count(int A[][11], int B[][11])
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cnt += A[i][j] ^ B[i][j];
        }
    }
    return cnt;
}
int main()
{
    int A[11][11], B[11][11];
    int m = 99999999;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    m = min(m, count(A, B));
    roll(A);
    m = min(m, count(A, B));
    roll(A);
    m = min(m, count(A, B));
    reverse(A);
    m = min(m, count(A, B));
    roll(A);
    m = min(m, count(A, B));
    roll(A);
    m = min(m, count(A, B));
    printf("%d", m);
}