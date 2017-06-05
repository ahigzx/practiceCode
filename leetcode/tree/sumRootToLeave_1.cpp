#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }

};

class Solution {
    public:
        int sumNumbers(TreeNode* root) {
            if(root == NULL)
                return 0;
            int depth = 1;
            vector<int> nums;
            int pathSum = 0;
            int sum = 0;
            sumNumAndDep(root, 1, &pathSum, nums);
            for(auto num : nums)
            {
                int revs = reverseNum(num);
                sum += revs;
            }
            return sum;
            
        }
        void sumNumAndDep(TreeNode* root, int depth, int* pathSum, vector<int>& nums)
        {
            if(root == NULL)
                return;
            *pathSum += root->val * pow(10, depth-1);
            int pre = *pathSum;
            if(root->left == NULL && root->right == NULL)
            {
                nums.push_back(*pathSum);
                return;
            }
            sumNumAndDep(root->left, depth + 1, pathSum, nums);
            *pathSum = pre;
            sumNumAndDep(root->right, depth + 1, pathSum, nums);
        }

        int reverseNum(int num)
        {
            int tmp = num / 10;
            int res = num % 10;
            int pre = res;
            while(tmp != 0)
            {
                res = res * 10 + tmp % 10;
                if(res / 10 != pre)
                    return 0;
                tmp /= 10;
                pre = res;
            }
            return res;
        }

};

int main(void)
{
    TreeNode* root = new TreeNode(0);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    Solution so;
    cout << so.sumNumbers(root) << endl;;

}
