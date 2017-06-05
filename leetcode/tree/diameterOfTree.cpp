/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {
 *
 *       }
 *        * 
 *   };
 *    */
class Solution {

    public:
        int diameterOfBinaryTree(TreeNode* root) {
            if(root == NULL)
                return 0;
            int rootlen = Depth(root->left) + Depth(root->right);
            int leftlen = diameterOfBinaryTree(root->left);
            int rightlen = diameterOfBinaryTree(root->right);
            int max = rootlen;
            if(leftlen > rightlen && leftlen > rootlen)
            {
                return leftlen;
            }
            else if(leftlen < rightlen && rightlen > rootlen)
            {
                return rightlen;
            }
            else
            {
                return rootlen;
            }
            
        }
        int Depth(TreeNode* root)
        {
            if(root == NULL)
                return 0;
            if(root->left == NULL && root->right == NULL)
                return 1;
            else
            {
                return max(Depth(root->left), Depth(root->right)) + 1;
            }
        }

};
