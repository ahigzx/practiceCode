#include <iostream>

using namespace std;


typedef struct listNode
{
    int data;
    struct listNode *lchild;
    struct listNode *rchild;
}TreeNode;


void treeMirror(TreeNode* Tree)
{
    if(Tree == NULL)
    {
        return;
    }
    if(Tree->lchild == NULL && Tree->rchild != NULL)
    {
        return;
    }
    TreeNode* temp;
    temp = Tree->lchild;
    Tree->lchild = Tree->rchild;
    Tree->rchild = temp;
    if(Tree->lchild)
    {
        treeMirror(Tree->lchild);
    }
    if(Tree->rchild)
    {
        treeMirror(Tree->rchild);
    }
}
