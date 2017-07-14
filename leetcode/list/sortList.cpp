class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            if(head == NULL)
                return NULL;
            if(head->next == NULL)
                return head;
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* pre = NULL;
            while(fast != NULL && fast->next != NULL)
            {
               fast = fast->next->next;
               pre = slow;
               slow = slow->next;
            }
            pre->next = NULL;
            ListNode* mid = slow;
            ListNode* leftHalf = sortList(head);
            ListNode* rightHalf = sortList(mid);
            return mergeList(leftHalf, rightHalf);
        }
        ListNode* mergeList(ListNode* list1, ListNode* list2)
        {
            ListNode* newHead = NULL;
            if(list1->val < list2->val)
            {
                newHead = list1;
                list1 = list1->next;
            }
            else
            {
                newhead = list2;
                list2 = list2->next;
            }
            ListNode* index = newHead;
            while(list1 != NULL && list2 != NULL)
            {
                if(list1->val < list2->val)
                {
                    index->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    index->next = list2;
                    list2 = list2->next;
                }
                index = index->next;
            }
            if(list1)
            {
                index->next = list1;
            }
            if(list2)
            {
                index->next = list2;
            }
            return newHead;
        }
}
