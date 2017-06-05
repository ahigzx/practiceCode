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
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            TreeNode* index = root;
            stack<TreeNode*> stk;
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
                    stk.pop();
                    result.push_back(index->val);
                    index = index->right;
                }
            }
            return result;

        }

}
