#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){

    }
};
class Solution {

    public:
        vector<int> findMode(TreeNode* root) 
        {
            vector<int> Vmode;
            map <int, int> m_count;
            int Max = 0;
            if(root)
            {
                findModeMax(m_count, root, Max);
                for(auto x: m_count)
                {
                    if(x.second == Max)
                    {
                        Vmode.push_back(x.first);
                    }
                }
            }
                
            return Vmode;
        }

        void findModeMax(map<int, int>& map, TreeNode* root, int& max)
        {
            if(root)
            {
                int count = ++map[root->val];
                if(count > max)
                {
                    max = count;
                }
                if(root->left)
                {
                    findModeMax(map, root->left, max);
                }
                if(root->right)
                {
                    findModeMax(map, root->right, max);
                }
            }
        }

};


int main(void)
{

}
