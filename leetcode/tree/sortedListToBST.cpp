class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            if(head == NULL)
                return NULL;
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* pre = NULL;
            TreeNode* root = new TreeNode(slow->val);
            if(head->next == NULL)
                return root;
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            }
            ListNode* right = slow->next;
            ListNode* left = head;
            if(left != slow)
            {
                pre->next = NULL;
                root->left = sortedListToBST(left);
            }
            root->right = sortedListToBST(right);
            return root;
        }
};
