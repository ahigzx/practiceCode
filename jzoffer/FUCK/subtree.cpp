#include <iostream>

using namespace std;

typedef struct tree
{
    int val;
    struct tree* left;
    struct tree* right;
}TreeNode;

/*
 */
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{

   bool result = false;
   if(pRoot1 != NULL && pRoot2 != NULL)
   {
       if(pRoot1->val == pRoot2->val)
       {
           result = IsSubtree(pRoot1, pRoot2);
       } //下面如果用else则当前相等的情况下result为false即返回false,没法继续跟踪左右子树

       if(!result)
       {
           result = HasSubtree(pRoot1->left, pRoot2); 
       }
       if(!result)
       {
           result = HasSubtree(free->right, pRoot2);
       }
   }
   return result;
}

bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2) //这个函数在根节点相等时判断是否为子树
{
    if(pRoot2 == NULL) //如果子树递归到空子树(到根节点时还想相等)
        return true;
    if(pRoot1 == NULL) //顺序不能反,此逻辑为如果root2不空而递归到root1为空则否，如果和上面判断反过来就是root1为空时直接否，root1不为空时root2为空则为true
        return false;
    
    if(pRoot1->val != pRoot2->val) //递归退出条件 第一次时必然相等
        return false;

    return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
}
