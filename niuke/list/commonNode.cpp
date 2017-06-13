class Common {
    public:
        vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
            vector<int> res;
            if(headA == NULL || headB == NULL)
                return res;
            while(headA != NULL && headB != NULL)
            {
                if(headA->val == headB->val)
                {
                    res.push(headA->val);
                    headA = headA->next;
                    headB = headB->next;
                }
                else if(headA->val < headB->val)
                {
                    headA = headA->next;
                }
                else
                {
                    headB = headB->next;
                }
            }
            return res;
        }
};
