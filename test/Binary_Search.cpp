#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int Binary_Search(int k, vector<int> arr)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // 오버플로우 방지

        if (arr[mid] == k)
            return mid; // 찾은 경우
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1; // 찾지 못한 경우
}

int main()
{
    vector<int> arr = {3, 1, 9, 8, 7, 2, 5};
    sort(arr.begin(), arr.end());

    int result = Binary_Search(7, arr);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");
    return 0;
}