#include <bits/stdc++.h>
using namespace std;

int lower_bound(int k, vector<int> arr)
{
    int start = 0, end = arr.size();
    while (start < end)
    {
        int mid = start + (end - start) / 2; // 오버플로우 방지
        if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid;
    }
    return start; // 값이 k 이상인 최초 인덱스
}

int upper_bound(int k, vector<int> arr)
{
    int start = 0, end = arr.size();
    while (start < end)
    {
        int mid = start + (end - start) / 2; // 오버플로우 방지
        if (arr[mid] <= k)
            start = mid + 1;
        else
            end = mid;
    }
    return start; // 값이 k 초과인 최초 인덱스
}

int main()
{
}