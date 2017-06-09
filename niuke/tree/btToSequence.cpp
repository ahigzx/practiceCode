class TreeToString {
    public:
        string toString(TreeNode* root) {
            string str;
            if(root == NULL)
                return str;
            treeSequence(root, str);
            return str;
        }

        void treeSequence(TreeNode* root, string& str)
        {
            str += num2str(root->val);
            str.push_back('!');
            if(root->left)
            {
                treeSequence(root->left, str);
            }
            else
            {
                str += string("#!");
            }
            if(root->right)
            {
                treeSequence(root->right, str);
            }
            else
            {
                str += string("#!");
            }
        }

        string num2str(int num)
        {
            char s[10] = {
                0
            };
            sprintf(s, "%d", num);
            return string(s);
        }

};
