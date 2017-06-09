#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {}
};

class TreeToSequence {
    public:
        vector<vector<int> > convert(TreeNode* root) {
            vector<vector<int>> result;
            if(root)
            {
                result.push_back(preorder(root));
                result.push_back(inorder(root));
                result.push_back(postorder(root));
            }
            return result;
        }

        vector<int> preorder1(TreeNode* root)
        {
            stack<TreeNode*> stk;
            TreeNode* cur = NULL;
            vector<int> preSequence;
            stk.push(root);
            while(!stk.empty())
            {
                cur = stk.top();
                preSequence.push_back(cur->val);
                stk.pop();
                if(cur->right)
                {
                    stk.push(cur->right);
                }
                if(cur->left)
                {
                    stk.push(cur->left);
                }
            }
            return preSequence;
        }

        vector<int> preorder(TreeNode* root)
        {
            stack<TreeNode*> stk;
            TreeNode* index = root;
            vector<int> preSequence;
            while(index != NULL || !stk.empty())
            {
                while(index)
                {
                    preSequence.push_back(index->val);
                    stk.push(index);
                    index = index->left;
                }
                if(!stk.empty())
                {
                    index = stk.top();
                    stk.pop();
                    index = index->right;
                }
            }
            return preSequence;
        }
        vector<int> inorder(TreeNode* root)
        {
            stack<TreeNode*> stk;
            TreeNode* index = root;
            vector<int> inSequence;
            while(index != NULL || !stk.empty())
            {
                while(index)
                {
                    stk.push(index);
                    index = index->left;
                }
                if(!stk.empty())
                {
                    index = stk.top();
                    inSequence.push_back(index->val);
                    stk.pop();
                    index = index->right;
                }
            }
            return inSequence;
        }
        vector<int> postorder(TreeNode* root)
        {
            stack<TreeNode*> stk;
            TreeNode* cur = NULL;
            TreeNode* pre = NULL;
            vector<int> postSequence;
            stk.push(root);
            while(!stk.empty())
            {
                cur = stk.top();
                if((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right)))
                {
                    postSequence.push_back(cur->val);
                    pre = cur;
                    stk.pop();
                }
                else
                {
                    if(cur->right)
                    {
                        stk.push(cur->right);
                    }
                    if(cur->left)
                    {
                        stk.push(cur->left);
                    }
                }
            }
            return postSequence;
        }

};
