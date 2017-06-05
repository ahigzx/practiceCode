/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {
 *
 *      }
 *       * 
 *   };
 *    */
class Solution {

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* lindex1 = l1;
            ListNode* lindex2 = l2;
            ListNode* head = new ListNode(0);
            newList->next = NULL;
            ListNode* newIndex = head;
            int sum = 0;
            bool isCarry = false;
            while(lindex2!= NULL || lindex1 != NULL)
            {
                if(lindex1)
                {
                    sum += lindex1->val;
                    lindex1 = lindex1->next;
                }
                if(lindex2)
                {
                    sum += lindex1->val;
                    lindex2 = lindex2->next;
                }
                if(isCarry)
                {
                    ++sum;
                    isCarry = false;
                }
                if(sum > 9)
                {
                   isCarry = true; 
                   sum -= 10;
                }
                ListNode* newNode = new ListNode(sum);
                newNode->next = NULL;
                newIndex->next = newNode;
                newIndex = newIndex->next;
                sum = 0;
            }
            if(isCarry)
            {
                ListNode* newNode = new ListNode(1);
                newNode->next = NULL;
                newIndex->next = newNode;
            }

            return head->next;

        }

}
