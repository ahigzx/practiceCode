#include <iostream>
#include <queue>

using namespace std;

typedef struct listNode
{
    int data;
    struct listNode *lchild;
    struct listNode *rchild;
}TreeNode;

void levelVisit(TreeNode* Tree)
{
    if(Tree == NULL)
        return;

    queue<TreeNode*> Tqueue;
    
    Tqueue.push(Tree);

    while(Tqueue.size() != 0)
    {
        TreeNode* fnode = Tqueue.front();
        Tqueue.pop();
        cout << fnode->data << " ";
        if(fnode->lchild)
        {
            Tqueue.push(fnode->lchild);
        }
        if(fnode->rchild)
        {
            Tqueue.push(fnode->rchild);
        }
    }
    cout << endl;
}


int main()
{

}
    
