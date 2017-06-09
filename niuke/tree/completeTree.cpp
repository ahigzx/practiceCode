class CheckCompletion {
    public:
        bool chk(TreeNode* root) {
            if(root == NULL)
                return false;
            queue<TreeNode*> que;
            que.push(root);
            TreeNode* cur = NULL;
            bool rightEmpty = false;
            while(!que.empty())
            {
                cur = que.front();
                if((cur->right && cur->left == NULL) || (rightEmpty == true && (cur->left || cur->right)))
                {
                    return false;
                }
                else if(cur->right == NULL)
                {
                    rightEmpty = true;
                }
                que.pop();
                if(cur->left)
                {
                    que.push(cur->left);
                }
                if(cur->right)
                {
                    que.push(cur->right);
                }
            }
            return true;
        }
}
