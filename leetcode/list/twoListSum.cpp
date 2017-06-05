#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x){}
};
 
class Solution {

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

           int l1len = 0; 
           int l2len = 0;
           ListNode* rvsL1 = reverseList(l1, &l1len);
           ListNode* rvsL2 = reverseList(l2, &l2len);
           bool isCarry = false;
           ListNode* newList = (l1len >= l2len) ? rvsL1 : rvsL2;
           ListNode* head = newList;
           ListNode* pre;
           while(rvsL1 != NULL && rvsL2 != NULL)
           {
               int sum = isCarry ? rvsL1->val + rvsL2->val + 1 : rvsL1->val + rvsL2->val;
               isCarry = false;
               if(sum > 9)
               {
                   isCarry = true;
                   sum -= 10;
               }
               rvsL1 = rvsL1->next;
               rvsL2 = rvsL2->next;
               newList->val = sum;
               pre = newList;
               newList = newList->next;
           }
           while(isCarry)
           {
               if(newList)
               {
                   (newList->val)++;
                   if(newList->val > 9)
                   {
                       isCarry = true;
                       pre = newList;
                       newList->val -= 10;
                       newList = newList->next;
                   }
                   else
                   {
                       isCaryy = false;
                   }
               }
               else
               {
                   ListNode* newNode = new ListNode(1);
                   pre->next = newNode;
                   newList = newNode;
                   isCarry = false;
               }
           }
           int len;
           return reverseList(head, &len);


        }
        ListNode* reverseList(ListNode* root, int* len)
        {
            if(root == NULL)
                return NULL;
            ListNode* pre = root;
            ListNode* index = pre->next;
            *len = 1;
            pre->next = NULL;
            ListNode* next;
            while(index)
            {
                ++(*len);
                next = index->next;
                index->next = pre;
                pre = index;
                index = next;
            }
            return pre;
        }
};

ListNode* buildList(vector<int> nums)
{
    int len = nums.size();
    ListNode* head = new ListNode(nums[0]);
    ListNode* index = head;
    for(int i = 1; i < len; i++)
    {
        ListNode* node = new ListNode(nums[i]);
        node->next = NULL;
        index->next = node;
        index = index->next;
    }
    return head;
}

void print(ListNode* node)
{
    ListNode* index = node;
    while(index)
    {
        cout << index->val << " ";
        index = index->next;
    }
    cout << endl;
}

int main(void)
{
    vector<int> nums1{
        7,2,4,3
    };
    vector<int> nums2{
        5,6,4 
    };
    ListNode *l1 = buildList(nums1);
    ListNode *l2 = buildList(nums2);
    Solution so;
    ListNode* newList = so.addTwoNumbers(l1, l2);
    print(newList);
}
