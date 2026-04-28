#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data = 0;
    Node *prev = NULL;
    Node *next = NULL;
} Node;
typedef struct LinkedList
{
    int size = 0;
    Node *head;
    Node *tail;
} LinkedList;

Node *MakeNode(int data = 0)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void push_next(LinkedList *LL, Node *node, int data)
{
    if (node->next == NULL) // tail의 뒤쪽 추가 불가능
        return;
    Node *newNode = MakeNode(data);

    newNode->next = node->next;
    newNode->prev = node;

    // newNode->next->prev = newNode와 동일하다
    node->next->prev = newNode;
    node->next = newNode;
    LL->size++;
}

void push_prev(LinkedList *LL, Node *node, int data)
{
    if (node->prev == NULL) // head의 앞쪽 추가 불가능
        return;
    Node *newNode = MakeNode(data);

    newNode->next = node;
    newNode->prev = node->prev;

    // newNode->prev->next = newNode와 동일하다
    node->prev->next = newNode;
    node->prev = newNode;
    LL->size++;
}

void pop(LinkedList *LL, Node *node)
{
    Node *prev = node->prev;
    Node *next = node->next;

    if (prev == NULL || next == NULL || !LL->size) // head, tail 삭제 불가능
        return;

    prev->next = next;
    next->prev = prev;
    LL->size--;

    free(node);
}

void initLL(LinkedList *LL)
{
    LL->head = MakeNode();
    LL->tail = MakeNode();
    LL->head->next = LL->tail;
    LL->tail->prev = LL->head;
}

void TraversalLL(LinkedList LL)
{
    Node *now = LL.head->next;
    printf("size: %d\ndata: ", LL.size);
    while (now->next != NULL)
    {
        printf("%d ", now->data);
        now = now->next;
    }
    puts("");
}

void SearchLL(LinkedList LL, int findData)
{
    Node *now = LL.head->next;
    while (now->next != NULL)
    {
        if (now->data == findData)
        {
            printf("Find %d\n", findData);
            return;
        }
        now = now->next;
    }
    printf("Can't Find %d\n", findData);
}

int main()
{
    LinkedList LL;
    initLL(&LL);
    push_next(&LL, LL.head, 10);
    push_prev(&LL, LL.tail, 15);
    push_prev(&LL, LL.tail, 13);
    push_prev(&LL, LL.tail, 25);

    pop(&LL, LL.head->next);

    TraversalLL(LL);

    SearchLL(LL, 13);
    SearchLL(LL, 10);
    return 0;
}
