class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL)
                return;
            while(root)
            {
                TreeLinkNode* idx = root->left;
                TreeLinkNode* pre = NULL;
                while(idx)
                {
                    if(idx->left)
                    {
                        if(pre)
                            pre->next = idx - left;
                        if(idx->right)
                        {
                            idx->left->next = idx->right;
                            pre = idx->right;
                        }
                        else
                        {
                            pre = idx->left;
                        }
                    }
                    else if(idx->right)
                    {
                        pre->next = idx->right;
                        pre = idx->right;
                    }
                    idx = idx->next;
                }
                root = root->left != NULL ? root->left : root->right;
            }
        }
};
