#include <iostream>

using namespace std;


struct Binarytree
{
    int val;
    Binarytree* left;
    Binarytree* right;
}TreeNode;

TreeNode* convert(TreeNode* proot)
{
    if(proot == NULL)
        return NULL;
    TreeNode* plisthead = proot;
    while(plisthead->left)
    {
        plisthead = plisthead->left;
    }
    convertList(proot);
    return plisthead;
}

void createBiTree(BiTree &T)  
{
    int c;  
    cin >> c;  
    if('#' == c)  
        T = NULL;  
    else  
    {

        T = new BiTreeNode;  
        T->data = c;  
        createBiTree(T->leftChild);  
        createBiTree(T->rightChild);  

    }  

}

void convertList(TreeNode* proot) //前序写法 比书上的麻烦
{
    TreeNode* pNode = proot;
    TreeNode* lchild = proot->left;
    TreeNode* rchild = proot->right;
    TreeNode* pleftright = lchild;
    TreeNode* prightleft = rchild;
    if(pleftright)
    {
        while(pleftright->right)
        {
            pleftright = pleftright->right;
        }
        pNode->left = pleftright;
        pleftright->right = pNode;
    }

    if(prightleft)
    {
        while(prightleft->left)
        {
            prightleft = prightleft->left;
        }
        pNode->right = prightleft;
        prightleft->left = pNode;
    }
    if(lchild)
    {
        convertList(lchild);
    }
    if(rchild)
    {
        convertList(rchild);
    }
}
