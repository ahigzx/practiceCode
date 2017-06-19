#include <iostream>
#include <vector>


typedef struct tree
{
    int val;
    struct tree* left;
    struct tree* right;
}TreeNode;

void sumOfPath(TreeNode* root, int number, vector<int>& vec, int sum)
{
    sum += root->val;
    vec.push_back(root->val);

    if(sum == number && (root->left == NULL && root->right == NULL))
    {
        cout << "A path is found :"
        for(auto x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    if(root->left)
    {
        sumOfPath(root->left, number, vec, sum);
    }
    if(root->right)
    {
        sumOfPath(root->right, number, vec, sum);
    }

    vec.pop_back();
}

void path(TreeNode* root, int number)
{
    if(root == NULL)
        return;
    int sum = 0;
    vector<int> vecStk;
    sumOfPath(root, number, &vecStk, sum);
}
