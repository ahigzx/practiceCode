class Solution {
    public:
        TreeNode* KthNode(TreeNode* pRoot, int k)
        {
            if(pRoot == NULL || k <= 0)
                return NULL;
            stack<TreeNode*> stk;
            TreeNode* node = pRoot;
            while(node != NULL || !stk.empty())
            {
                while(node)
                {
                    stk.push(node);
                    node = node->left;
                }
                if(!stk.empty())
                {
                    node = stk.top();
                    stk.pop();
                    --k;
                    if(k == 0)
                    {
                        return node;
                    }
                    node = node->right;
                }
            }
            return NULL;
        }
        
};
