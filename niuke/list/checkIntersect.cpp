class CheckIntersect {
    public:
        bool chkIntersect(ListNode* headA, ListNode* headB) {
            if(headA == NULL || headB == NULL)
                return false;
            ListNode* aCur = headA;
            ListNode* bCur = headB;
            int lenA = 0;
            int lenB = 0;
            while(aCur != NULL)
            {
                aCur = aCur->next;
                ++lenA;
            }
            while(bCur != NULL)
            {
                bCur = bCur->next;
                ++lenB;
            }
            aCur = headA;
            bCur = headB;
            if(lenA > lenB)
            {
                for(int diff = lenA - lenB; diff > 0; diff--)
                {
                    aCur = aCur->next;
                }
            }
            else
            {
                for(int diff = lenB - lenA; diff > 0; diff--)
                {
                    bCur = bCur->next;
                }
            }
            while(aCur != NULL && bCur != NULL)
            {
                if(aCur == bCur)
                    return true;
                aCur = aCur->next;
                bCur = bCur->next;
            }
            return false;
        }
};
