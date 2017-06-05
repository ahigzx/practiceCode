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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            if(root == NULL)
                return result;
            stack<TreeNode*> stk;
            TreeNode* pre = NULL;
            stk.push(root);
            TreeNode* index;
            while(!stk.empty())
            {
                index = stk.top();
                if((index->left == NULL && index->right == NULL) || (pre != NULL && (pre == index->left || pre == index->right)))
                {
                    result.push_back(index);
                    stk.pop();
                    pre = index;
                }
                else
                {
                    if(index->right != NULL)
                    {
                        stk.push(index->right);
                    }
                    if(index->left != NULL)
                    {
                        stk.push(index->left);
                    }
                }
            }
            return result;
        }
            

        }
        
};
