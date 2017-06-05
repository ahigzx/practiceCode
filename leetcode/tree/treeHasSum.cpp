class Solution {
    public:
        bool hasPathSum(TreeNode* root, int sum) {
            if(root == NULL)
                return false;
            sum -= root->val;
            if(root->left == NULL && root->right == NULL)
            {
                if(sum == 0)
                {
                    return true;
                }
            }
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        }
};
