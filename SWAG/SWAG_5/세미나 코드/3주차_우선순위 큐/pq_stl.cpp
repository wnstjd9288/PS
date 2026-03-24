#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef struct gird
{
    int x;
    int y;
} grid;

// 비교자 선언
struct cmp
{
    bool operator()(grid a, grid b)
    {
        if (a.x > b.x) // a > b가 true면 min heap, a < b가 true면 max heap
            return true;
        else if (a.x == b.x)
            return a.y > b.y;
        else
            return false;
    }
};

int main()
{
    priority_queue<int> pq;
    // 1 ~ 5 순차 삽입
    for (int i = 1; i <= 5; i++)
        pq.push(i);
    for (int i = 0; i < 5; i++)
    {
        // 결과는 5 4 3 2 1
        // STL의 우선순위 큐는 기본적으로 Max Heap을 채택
        printf("%d ", pq.top());
        pq.pop();
    }
    puts("");

    // greater 비교자를 사용하여 최소 힙으로 설정
    priority_queue<int, vector<int>, greater<int>> pq_min;
    // 1 ~ 5 순차 삽입
    for (int i = 1; i <= 5; i++)
        pq_min.push(i);
    for (int i = 0; i < 5; i++)
    {
        // 결과는 1 2 3 4 5
        printf("%d ", pq_min.top());
        pq_min.pop();
    }
    puts("");
    // 구조체라면?
    priority_queue<grid> pq_grid;
    for (int i = 1; i <= 5; i++)
    {
        grid a = {i, 6 - i};
        pq_grid.push(a); // 에러 발생
    }
    for (int i = 0; i < 5; i++)
    {
        printf("(%d, %d) ", pq_grid.top().x, pq_grid.top().y);
        pq_grid.pop();
    }

    // 비교자를 직접 생성해 주어야 한다!
    priority_queue<grid, vector<grid>, cmp> pq_grid;
    for (int i = 1; i <= 5; i++)
    {
        grid a = {i, 6 - i};
        pq_grid.push(a);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("(%d, %d) ", pq_grid.top().x, pq_grid.top().y);
        pq_grid.pop();
    }
}