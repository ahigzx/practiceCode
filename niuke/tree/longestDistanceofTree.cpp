class LongestDistance {
    public:
        int findLongest(TreeNode* root) {
            if(root == NULL)
                return 0;
            int tmpMax = root->val;
            maxSum(root, &tmpMax);
            return tmpMax;
        }
        int maxSum(TreeNode* root, int *tmpMax)
        {
            if(root == NULL)
                return 0;
            int sum = root->val;
            int left = maxSum(root->left, tmpMax);
            int right = maxSum(root->right, tmpMax);
            if(left > 0)
            {
                sum += left;
            }
            if(right > 0)
            {
                sum += right;
            }
            if(sum > *tmpMax)
            {
                *tmpMax = sum;
            }
            return max(max(left + root->val, right + root->val), root->val)
        }
};
