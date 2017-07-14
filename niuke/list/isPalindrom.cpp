class Palindrome {
    public:
        bool isPalindrome(ListNode* pHead) {
            if(pHead == NULL)
                return false;
            if(pHead->next == NULL)
                return true;
            ListNode* fast = pHead;
            ListNode* slow = pHead;
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            ListNode* right = reverseList(slow);
            ListNode* left = pHead;
            while(right != NULL && left != NULL)
            {
                if(right->val != left->val)
                    return false;
                else
                {
                    right = right->next;
                    left = left->next;
                }
            }
            slow = reverseList(right);
            return true;
        }
        ListNode* reverseList(ListNode* head)
        {
            if(head == NULL)
            {
                return NULL;
            }
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
