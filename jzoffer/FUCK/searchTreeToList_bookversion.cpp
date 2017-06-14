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
    plisthead = proot;
    TreeNode* plastNode == NULL;
    
    while(plisthead->left)
    {
        plisthead = plisthead->left;
    }
    convertList(proot, &plastNode);
    return plisthead;
}

void convertList(TreeNode* proot, TreeNode** plastNode) //传二级指针因为从NULL到指向某个节点，内存地址发生变化
{

    if(proot == NULL)
        return;

    if(proot->left)
    {
        convertList(proot->left, plastNode);
    }

    proot->left = *plastNode;
    if(*plastNode)
    {
        *plastNode->right = proot;
    }
    *plastNode = proot;
    if(proot->right)
    {
        convertList(proot->right, plastNode);
    }

}
