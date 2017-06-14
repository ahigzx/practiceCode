#include <iostrea>
#include <algorithm>

using namespace std;

struct binaryTreeNode{
    binaryTreeNode* left;
    binaryTreeNode* right;
    int data;
};


int DepthOfTree(binaryTreeNode* tree)
{
    if(tree == NULL)
        return 0;
    return max(DepthOfTree(tree->left), DepthOfTree(tree->right)) + 1;
}

bool isBalanceBinarytree(binaryTreeNode* tree, int& depth)
{
    if(tree == NULL)
    {
        depth = 0;
        return true;
    }
    int left;
    int right;
    if(isBalanceBinarytree(tree->left, left)&&isBalanceBinarytree(tree->right, right))
    {
        int diff = left - right;
        if(diff < 1 && diff > -1)
        {
            depth = max(left, right) + 1;
            return true;
        }
    }
    return false;
}
