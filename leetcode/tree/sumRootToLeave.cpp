#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }

};

class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            if(root == NULL)
                return 0;
            int sum = 0;
            dfsSum(root, root->val, &sum);
            return sum;
        }
        
        void dfsSum(TreeNode* root, int num, int *sum)
        {
            if(root == NULL)
                return;
            num = num * 10 + root->val; //将前一个根节点上已经计算出的值加入
            if(root->left == NULL && root->right == NULL)
            {
                *sum += num;  //在叶子结点处累加到和中
            }
            dfsSum(root->left, num, sum);  //将当前和计算完传下递归累加
            dfsSum(root->right, num, sum);
            
        }

}
