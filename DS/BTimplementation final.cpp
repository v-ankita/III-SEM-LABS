#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};
struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;

    queue<Node *> q;
    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.push(root);
    while (!q.empty())
    {

        p = q.front();
        q.pop();
        printf("enter left child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;

            q.push(t);
        }
        printf("enter right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;

            q.push(t);
        }
    }
}

void IPreorder(struct Node *p)
{
    stack<Node *> stk;
    while (p || !stk.empty())
    {
        if (p)
        {
            printf("%d ", p->data);
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}
void IInorder(struct Node *p)
{
    stack<Node *> stk;
    while (p || !stk.empty())
    {
        if (p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void IPostorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    Node *node;
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->lchild)
            s1.push(node->lchild);
        if (node->rchild)
            s1.push(node->rchild);
    }
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}
unsigned int getLeafCount(Node *node)
{
    if (node == NULL)
        return 0;
    if (node->lchild == NULL && node->rchild == NULL)
        return 1;
    else
        return getLeafCount(node->lchild) +
               getLeafCount(node->rchild);
}
int main()
{
    cout << "Create a Binary Tree...\n";
    Treecreate();
    cout << "\nPreOrder: ";
    IPreorder(root);
    cout << endl;
    cout << "InOrder: ";
    IInorder(root);
    cout << endl;
    cout << "PostOrder: ";
    IPostorder(root);
    cout << "\nLeaf count is: " << getLeafCount(root) << endl;
    return 0;
}
