#include <stdio.h>
#define MAX_SIZE 100000
typedef struct Node
{
    int value;
} Node;

typedef struct Heap
{
    Node tree[MAX_SIZE];
    int size = 0;
} Heap;

void init(Heap *pq)
{
    // 초기화 함수
    for (int i = 0; i < MAX_SIZE; i++)
        pq->tree[i].value = 0;
    pq->size = 0;
}
void heapify_up(Heap *pq, int pos)
{
    // 현재 위치 기준 부모가 존재하지 않으면 return
    if (pos / 2 <= 0)
        return;
    // 현재 노드의 값이 부모보다 작으면 swap :: Min heap 기준
    if (pq->tree[pos].value < pq->tree[pos / 2].value)
    {
        int temp = pq->tree[pos].value;
        pq->tree[pos].value = pq->tree[pos / 2].value;
        pq->tree[pos / 2].value = temp;
        // 재귀적으로 실행
        heapify_up(pq, pos / 2);
    }
}
void heapify_down(Heap *pq, int pos)
{
    // 왼쪽 자식의 위치가 범위를 벗어나면 return
    if (pos * 2 > pq->size)
        return;
    // 왼쪽, 오른쪽 자식 중 선택할 자식 flag
    int go_left = 0, go_right = 0;
    // 왼쪽 자식과 우선순위 비교
    if (pq->tree[pos].value > pq->tree[pos * 2].value)
    {
        // 플래그 활성화
        go_left = 1;
    }
    // 오른쪽 자식과 비교조건 :: 트리의 크기 내에 존재할것
    if (pos * 2 + 1 <= pq->size)
    {
        // 자식들 중 우선순위가 높은쪽을 택하도록 설계
        if (go_left)
        {
            if (pq->tree[pos * 2].value > pq->tree[pos * 2 + 1].value)
            {
                go_left = 0;
                go_right = 1;
            }
        }
        else
        {
            if (pq->tree[pos].value > pq->tree[pos * 2 + 1].value)
            {
                go_right = 1;
            }
        }
    }
    // 재귀적으로 실행
    if (go_right)
    {
        int temp = pq->tree[pos].value;
        pq->tree[pos].value = pq->tree[pos * 2 + 1].value;
        pq->tree[pos * 2 + 1].value = temp;
        heapify_down(pq, pos * 2 + 1);
    }
    else if (go_left)
    {
        int temp = pq->tree[pos].value;
        pq->tree[pos].value = pq->tree[pos * 2].value;
        pq->tree[pos * 2].value = temp;
        heapify_down(pq, pos * 2);
    }
    return;
}
void Push(Heap *pq, int n)
{
    // size의 최초값이 0이므로 size를 먼저 증가시키고 삽입
    pq->size++;
    pq->tree[pq->size].value = n;
    // 우선순위에 따른 위치정렬
    heapify_up(pq, pq->size);
}
int Pop(Heap *pq)
{
    int res = pq->tree[1].value;
    // 가장 마지막 값을 루트로 이동
    pq->tree[1].value = pq->tree[pq->size].value;
    pq->size--;
    // 우선순위에 따른 위치정렬
    heapify_down(pq, 1);
    return res;
}
void Print_Tree(Heap *bt)
{
    int k = 1;
    int enter = 1;
    printf("size: %d\n", bt->size);
    for (int i = 1; i <= bt->size; i++)
    {
        printf("%d ", bt->tree[i].value ? bt->tree[i].value : '.');
        if (i == enter)
        {
            puts("");
            k *= 2;
            enter += k;
        }
    }
    puts("");
}
int main()
{
    Heap pq;
    Push(&pq, 5);
    Push(&pq, 4);
    Push(&pq, 3);
    Push(&pq, 4);
    Push(&pq, 7);
    Push(&pq, 2);
    Push(&pq, 1);
    Print_Tree(&pq);
    for (int i = 0; i < 4; i++)
    {
        printf("pop: %d\n", Pop(&pq));
        Print_Tree(&pq);
    }
}