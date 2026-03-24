    #include <stdio.h>
#define MAX_SIZE 129

typedef struct Node
{
    char data;
} Node;
typedef struct Tree
{
    Node tree[MAX_SIZE];
    int size = 0;
} Tree;
int index[300];

void init_tree(Tree *bt, char root)
{

    for (int i = 0; i < MAX_SIZE; i++)
        bt->tree[i].data = 0;
    bt->tree[1].data = root;
    bt->size = 1;
    for (int i = 0; i < 300; i++)
        index[i] = 0;
    index[root] = 1;
}
void resize(Tree *bt)
{
    for (int i = 1; i <= bt->size; i++)
    {
        if (bt->tree[i].data)
        {
            bt->size = i;
        }
    }
}

void Add(Tree *bt, char parent, char child, int is_right)
{
    if (!index[parent])
    {
        printf("invaild parent. log: %c, %c, %d\n", parent, child, is_right);
        return;
    }
    if (index[child])
    {
        printf("already exist child node. log: %c, %c, %d\n", parent, child, is_right);
        return;
    }
    if (bt->tree[index[parent] * 2 + (is_right ? 1 : 0)].data)
    {
        printf("child is full. log: %c, %c, %d\n", parent, child, is_right);
        return;
    }

    bt->tree[index[parent] * 2 + (is_right ? 1 : 0)].data = child;
    index[child] = index[parent] * 2 + (is_right ? 1 : 0);
    bt->size = bt->size < index[child] ? index[child] : bt->size;
}
void Delete(Tree *bt, char key, int depth = 0)
{
    if (!depth && !index[key])
    {
        printf("invaild key.\n");
        return;
    }
    if (!key)
        return;
    Delete(bt, bt->tree[index[key] * 2].data, depth + 1);
    Delete(bt, bt->tree[index[key] * 2 + 1].data, depth + 1);
    bt->tree[index[key]].data = 0;
    index[key] = 0;
    if (!depth)
        resize(bt);
}
void Replace(Tree *bt, char ori_key, char new_key)
{
    if (!index[ori_key])
    {
        printf("invaild original_key.\n");
        return;
    }
    if (index[new_key])
    {
        printf("new key is exist in tree\n");
        return;
    }
    bt->tree[index[ori_key]].data = new_key;
    index[new_key] = index[ori_key];
    index[ori_key] = 0;
}
void Print_Tree(Tree *bt)
{
    int k = 1;
    int enter = 1;
    printf("size: %d\n", bt->size);
    for (int i = 1; i <= bt->size; i++)
    {
        printf("%c ", bt->tree[i].data ? bt->tree[i].data : '.');
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
    Tree bt;
    init_tree(&bt, 'A');
    Add(&bt, 'A', 'B', 0);
    Add(&bt, 'A', 'C', 1);
    Add(&bt, 'B', 'D', 0);
    Add(&bt, 'B', 'E', 1);
    Add(&bt, 'C', 'F', 0);
    Add(&bt, 'C', 'G', 1);
    Add(&bt, 'D', 'H', 0);
    Add(&bt, 'G', 'I', 1);
    Print_Tree(&bt);
}