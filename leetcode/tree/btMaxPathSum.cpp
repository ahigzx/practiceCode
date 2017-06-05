struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }

};
 
class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            if(root == NULL)
                return 0;
            int tmpMax = root->val;
            maxSumSingle(root, &tmpMax);
            return tmpMax;
        }

        int maxSumSingle(TreeNode* root, int *tmpMax)
        {
            if(root == NULL)
            {
                return 0;
            }

            int leftSum = 0;
            int rightSum = 0;
            int maxSum = root->val;
            leftSum = maxSumSingle(root->left, tmpMax);
            rightSum = maxSumSingle(root->right, tmpMax);
            if(leftSum > 0)
            {
                maxSum += leftSum;
            }
            if(rightSum > 0)
            {
                maxSum += rightSum;
            }
            if(maxSum > *tmpMax)
            {
                *tmpMax = maxSum;//用tmpMax记录经过当前结点的路径的最大值，每次更新
            }
            return max(root->val, max(leftSum + root->val, rightSum + root->val)); //返回值不能是路径最大值，应该考虑到有分叉，应该返回以当前结点到某结点的路径的和
        }

};
