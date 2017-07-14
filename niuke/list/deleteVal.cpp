class ClearValue {
    public:
        ListNode* clear(ListNode* head, int val) {
            if(head == NULL)
                return NULL;
            ListNode* index = head;
            ListNode* pre = NULL;
            while(index != NULL)
            {
                if(index->val == val)
                {
                    if(index == head)
                    {
                        head = head->next;
                        index = index->next;
                    }
                    else
                    {
                        pre->next = index->next;
                        index = index->next;
                    }
                }
                else
                {
                    pre = index;
                    index = index->next;
                }
            }
            return head;
        }
};
