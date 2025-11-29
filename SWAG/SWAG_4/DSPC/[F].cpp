#include <bits/stdc++.h>
using namespace std;
vector<int> arr, arr_o;
unordered_map<int, int> m;
unordered_map<int, int> result;
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < 6; i++)
    {
        int a;
        scanf("%d", &a);
        arr_o.push_back(a);
        m[a] = 1;
    }
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    if (t == 1)
    {
        for (auto A : arr)
        {
            int index = A;
            while (1)
            {
                if (!m[(index) % 64 + 1])
                {
                    result[A] = (index) % 64 + 1;
                    m[(index) % 64 + 1] = 1;
                    break;
                }
                index++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", result[arr_o[i]]);
        }
    }
    else
    {
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int index = arr[i];
            while (1)
            {
                if (index <= 0)
                    index += 64;
                if (!m[index])
                {
                    result[arr[i]] = index;
                    m[index] = 1;
                    break;
                }
                index--;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", result[arr_o[i]]);
        }
    }
    return 0;
}