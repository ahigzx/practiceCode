#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> stk;
            TreeNode* index = root;
            while(index != NULL || !stk.empty())
            {
                while(index != NULL)
                {
                    result.push_back(index->val);
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
            return result;
            
        }
        
};
