#include <bits/stdc++.h>
char tree[100000001];
int pos[27];
void preorder(int now)
{
    if (tree[now] == 0)
        return;
    printf("%1c", tree[now]);
    preorder(now * 2);
    preorder(now * 2 + 1);
}
void inorder(int now)
{
    if (tree[now] == 0)
        return;
    inorder(now * 2);
    printf("%1c", tree[now]);
    inorder(now * 2 + 1);
}
void postorder(int now)
{
    if (tree[now] == 0)
        return;
    postorder(now * 2);
    postorder(now * 2 + 1);
    printf("%1c", tree[now]);
}
int main()
{
    int n;
    scanf("%d", &n);
    tree[1] = 'A';
    pos[0] = 1;
    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        scanf("%*c%1c %1c %1c", &a, &b, &c);
        if (b != '.')
        {
            tree[pos[a - 65] * 2] = b;
            pos[b - 65] = pos[a - 65] * 2;
        }
        if (c != '.')
        {
            tree[pos[a - 65] * 2 + 1] = c;
            pos[c - 65] = pos[a - 65] * 2 + 1;
        }
    }
    preorder(1);
    puts("");
    inorder(1);
    puts("");
    postorder(1);
    puts("");
}