class Solution {
    public:
        void reorderList(ListNode *head) {
            if(head == NULL || head->next == NULL)
                return;
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            ListNode* right = reverseList(slow);
            ListNode* cur = head;
            ListNode* next = head;
            ListNode* rnext = head;
            while(right != slow)
            {
                next = cur->next;
                cur->next = right;
                rnext = right->next;
                right->next = next;
                cur = next;
                right = rnext;
            }
        }
        ListNode* reverseList(ListNode* head)
        {
            if(head == NULL)
                return NULL;
            ListNode* pre = NULL;
            ListNode* next = NULL;
            while(head != NULL)
            {
                next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            return pre;
        }
};
