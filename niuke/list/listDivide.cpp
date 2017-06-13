class Divide {

    public:
        ListNode* listDivide(ListNode* head, int val) {
            if(head == NULL)
                return NULL;
            ListNode* smallList = NULL;
            ListNode* bigList = NULL;
            ListNode* equalList = NULL;
            ListNode* smallTail = NULL;
            ListNode* bigTail = NULL;
            ListNode* equalTail = NULL;
            while(head != NULL)
            {
                if(head->val < val)
                {
                    if(smallList == NULL)
                    {
                        smallList = head;
                        head = head->next;
                        smallList->next = NULL;
                        smallTail = smallList;
                    }
                    else
                    {
                        smallTail->next = head;
                        smallTail = smallTail->next;
                        head = head->next;
                        smallTail->next = NULL;
                    }
                }
                else if(head->val > val)
                {
                    if(bigList == NULL)
                    {
                        bigList = head;
                        head = head->next;
                        bigList->next = NULL;
                        bigTail = bigList;
                    }
                    else
                    {
                        bigTail->next = head;
                        bigTail = bigTail->next;
                        head = head->next;
                        bigTail->next = NULL;
                    }

                }
                else
                {
                    if(equalList == NULL)
                    {
                        equalList = head;
                        head = head->next;
                        equalList->next = NULL;
                        equalTail = equalList;
                    }
                    else
                    {
                        equalTail->next = head;
                        equalTail = equalTail->next;
                        head = head->next;
                        equalTail->next = NULL;
                    }

                }
            }
            if(smallList != NULL)
            {
                if(equalList != NULL)
                {
                    smallTail->next = equalList;
                    equalTail->next = bigList;
                }
                else
                {
                    smallTail->next = bigList;
                }
                return smallList;
            }
            else if(equalList != NULL)
            {
                equalTail->next = bigList;
                return equalList;
            }
            else
            {
                return bigList;
            }
        }
};
