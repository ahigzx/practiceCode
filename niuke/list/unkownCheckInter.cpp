class ChkIntersection {
    public:
        bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
            if(head1 == NULL || head2 == NULL)
                return false;
            ListNode* loop1Start = loopFirstNode(head1);
            ListNode* loop2Start = loopFirstNode(head2);
            int count1 = 0;
            int count2 = 0;
            ListNode* index1 = head1;
            ListNode* index2 = head2;
            if(loop1Start != NULL && loop2Start != NULL)
            {
                if(loop1Start != loop2Start)
                {
                    index1 = loop1Start;
                    while(index1 != loop2Start)
                    {
                        index1 = index1->next;
                        if(index1 == loop1Start)
                        {
                            return false;
                        }
                    }
                    return true;
                }
                else
                    return true;
            }
            else
            {
                if(loop1Start != NULL)
                {
                    while(index1 != loop1Start)
                    {
                        index1 = index1->next;
                        ++count1;
                    }
                    while(index2 != NULL)
                    {
                        index2 = index2->next;
                        ++count2;
                    }
                }
                else if(loop2Start != NULL)
                {
                    while(index2 != loop2Start)
                    {
                        index2 = index2->next;
                        ++count2;
                    }
                    while(index1 != NULL)
                    {
                        index1 = index1->next;
                        ++count1;
                    }
                }
                else
                {
                    while(index1 != NULL)
                    {
                        index1 = index1->next;
                        ++count1;
                    }
                    while(index2 != NULL)
                    {
                        index2 = index2->next;
                        ++count2;
                    }
                }

                index1 = head1;
                index2 = head2;
                if(count1 > count2)
                {
                    for(int diff = count1 - count2; diff > 0; diff--)
                    {
                        index1 = index1->next;
                    }
                }
                else
                {
                    for(int diff = count2 - count1; diff > 0; diff--)
                    {
                        index2 = index2->next;
                    }
                }
                while(index1 != index2 && index1 != NULL && index2 != NULL)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                    if(index1 == index2)
                    {
                        return true;
                    }
                }
                return false;
            }
        }

        ListNode* loopFirstNode(ListNode* head) 
        {
            if(head == NULL || head->next == NULL)
                return NULL;
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(fast == slow)
                {
                    slow = head;
                    while(fast != slow)
                    {
                        fast = fast->next;
                        slow = slow->next;
                    }
                    return fast;
                }
            }
            return NULL;
        }
};
