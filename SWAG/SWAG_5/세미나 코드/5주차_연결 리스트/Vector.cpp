#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;             // 배열 초기 크기 = 0
    vector<int> v2(4);          // 배열 초기 크기 = 4, 값은 모두 0
    vector<int> v3 = {1, 2, 3}; // 배열 초기 크기 = 3, 값은 순서대로 1, 2, 3

    vector<int> v;
    v.resize(100); // 배열의 크기를 100으로 설정

    printf("%d %d\n", v3.size(), v.size());

    v.clear(); // 벡터를 초기화하는 함수. v1과 동일한 상태가 된다.

    v3.push_back(50);      // 벡터의 가장 뒤쪽에 원소를 추가하는 연산
    printf("%d\n", v3[3]); // 일반 배열처럼 접근 가능하다.
}