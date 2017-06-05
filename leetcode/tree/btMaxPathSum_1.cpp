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
            int rootSum = maxSumRootToLeave(root->left) + maxSumRootToLeave(root->right) + root->val;
            int leftSum = 0;
            int rightSum = 0;
            int maxSum = rootSum;
            if(root->left)
            {
                leftSum = maxPathSum(root->left);
            }
            if(root->right)
            {
                rightSum = maxPathSum(root->right);
            }
            if(root->left && root->right)
            {
                maxSum = max(rootSum, max(leftSum, rightSum));
            }
            else if(root->left && (root->right == NULL))
            {
                maxSum = max(rootSum, leftSum);
            }
            else if(root->right && (root->left == NULL))
            {
                maxSum = max(rootSum, rightSum);
            }
            return maxSum;
        }

        int maxSumRootToLeave(TreeNode* root)
        {
            if(root == NULL)
            {
                return 0;
            }

            int leftSum = 0;
            int rightSum = 0;
            int maxSum = 0;
            if(root->left)
            {
                leftSum = maxSumRootToLeave(root->left);
            }
            if(root->right)
            {
                rightSum = maxSumRootToLeave(root->right);
            }
            if(root->left && root->right)
            {
                maxSum = max(leftSum, rightSum);
            }
            else if(root->left && (root->right == NULL))
            {
                maxSum += leftSum;
            }
            else if(root->right && (root->left == NULL))
            {
                maxSum += rightSum;
            }

            return maxSum + root->val;
        }

};
