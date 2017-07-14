class ChkLoop {
    public:
        int chkLoop(ListNode* head, int adjust) {
            if(head == NULL || head->next == NULL)
                return -1;
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow)
                    break;
            }
            if(fast == slow)
            {
                slow = head;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast->val;
            }
            else
            {
                return -1;
            }
        }
};
