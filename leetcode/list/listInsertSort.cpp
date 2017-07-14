class Solution {
    public:
        ListNode *insertionSortList(ListNode *head) {
            if(head == NULL)
                return NULL;
            ListNode* cur = head->next;
            ListNode* pre = head;
            ListNode* idx = head;
            ListNode* next = head;
            while(idx != cur && cur != NULL)
            {
                if(cur->val < head->val)
                {
                    next = cur->next;
                    cur->next = head;
                    pre->next = next;
                    head = cur;
                    cur = next;
                    idx = head;
                    continue;
                }
                if(idx == pre)
                {
                    pre = cur;
                    cur = cur->next;
                    idx = head;
                }
                else if((cur->val > idx->val && cur->val < idx->next->val) || cur->val == idx->val)
                {
                    next = cur->next;
                    cur->next = idx->next;
                    idx->next = cur;
                    pre->next = next;
                    cur = next;
                    idx = head;
                }
                else
                {
                    idx = idx->next;
                }
            }
            return head;

        }

};
