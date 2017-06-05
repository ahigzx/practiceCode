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
        vector<int> findFrequentTreeSum(TreeNode* root) {
            vector<int> SumofNode;
            vector<int> MostFrequent;
            if(root)
            {
                mostFrequentSubtree(root, SumofNode);
            }
            if(SumofNode.size())
            {
                int max = 0;
                int most_number;
                map<int, int> count;
                //后面这两步可以在下面那个函数中计算，传入map在计算出和的同时++count[]，并且同时可计算max
                for(auto i : SumofNode)
                {
                    ++count[i];
                }
                for(auto x : count)
                {
                    if(max < x.second)
                    {
                        max = x.second;
                    }
                }
                for(auto num : count)
                {
                    if(num.first == max)
                    {
                        MostFrequent.push_back(num.first);
                    }
                }
            }
            return MostFrequent;
        }

        int mostFrequentSubtree(TreeNode* root, vector<int>& vec)
        {
            if(root == NULL)
            {
                return 0;
            }
            if(root->left == NULL && root->right == NULL)
            {
                vec.push_back(root->val);
                return root->val;
            }
            int sum = mostFrequentSubtree(root->left, vec) + mostFrequentSubtree(root->right, vec) + root->val;
            vec.push_back(sum);
            return sum;
        }

}
