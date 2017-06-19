#include <iostream>

using namespace std;

typedef struct listNode
{
    int date;
    struct listNode *lchild;
    struct listNode *rchild;
}Listnode;

int findNum(int num,int *array,int size)
{
    if(array!=NULL&&size>0)
    {
        for(int i=0;i<size;i++)
        {
            if(array[i]==num)
            {
                return i;
            }
        }
    }
    return -1;
}

void printTree(Listnode *tree)
{
    if(tree!=NULL)
    {
        printTree(tree->lchild);
        cout << tree->date << endl;
        printTree(tree->rchild);
    }
}

Listnode *treeBuild(int *prearray, int *midarray, int size)
{
    if(prearray == NULL || midarray == NULL || size < 0)
        return NULL;
    Listnode *root = new Listnode();
    root->date = *prearray;
    int num = *prearray;
    int index = 0;
    if((index = findNum(num, midarray, size)) < 0)
    {
        return NULL;//throw exception("invalid input.");
    }
    int leftsize = index;
    int *leftPreArray = NULL;
    int *leftMidArray = NULL;
    if(leftsize > 0)
    {
        leftPreArray = prearray + 1;
        leftMidArray = midarray;
    }
    int rightsize = size - index - 1;
    int *rightPreArray = NULL;
    int *rightMidArray = NULL;
    if(rightsize > 0)
    {
        rightPreArray = prearray + index + 1;
        rightMidArray = midarray + index + 1;
    }
    root->lchild = treeBuild(leftPreArray, leftMidArray, leftsize);
    root->rchild = treeBuild(rightPreArray, rightMidArray, rightsize);
    return root;
}

int main(int argc, char *argv[])
{
    int pre[8] = {1,2,4,7,3,5,6,8};
    int mid[8] = {4,7,2,1,5,3,8,6};
    Listnode *tree;
    tree = treeBuild(pre, mid, 8);
    printTree(tree);
}
