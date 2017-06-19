#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

class KInverse {
    public:
        ListNode* inverse(ListNode* head, int k) {
            if(head == NULL)
                return 0;
            if(head->next == NULL || k == 1)
                return head;
            ListNode* cur = head;
            ListNode* next = NULL;
            ListNode* newTail = NULL;
            ListNode* newHead = NULL;
            ListNode* kth = NULL;
            int count = k;
            while(cur != NULL)
            {
                if((kth = kthNode(cur, k)) != NULL)   //有k个结点且返回第k个结点值
                {
                    if(cur == head)
                    {
                        next = kth->next; //next指向下一轮第一个结点
                        newHead = reversePart(cur, k);  //反转返回翻转后第一个结点
                        newTail = cur;  //reverse并不会改变cur的指向的结点，所以这里顺序应该是对的
                        cur = next;
                    }   
                    else
                    {
                        next = kth->next; //必须要在翻转之前记录下kth的next
                        newTail->next = reversePart(cur, k); //调用reversePart并不改变cur的值
                        newTail = cur;  //cur还是指向第一个
                        cur = next;
                    }   
                }   
                else     //不够k个结点
                {
                    if(cur == head)
                        return cur;
                    else
                    {
                        newTail->next = cur;
                        break;
                    }
                }
            }
            return newHead;
        }

        ListNode* kthNode(ListNode *head, int k) //有足够结点且返回最后一个
        {
            int count = k - 1;
            while(head->next != NULL && count > 0)
            {
                head = head->next;
                --count;
            }

            if(count == 0)
                return head;
            else
                return NULL;
        }

        ListNode* reversePart(ListNode* head, int k)  //这里已经将翻转后的最后一个结点的next指向空
        {
            int count = k;
            ListNode* cur = head;
            ListNode* pre = NULL;
            ListNode* next = NULL;
            while(count > 0)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                --count;
            }
            return pre;
        }
};

void print(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(void)
{
    ListNode* head = new ListNode(0);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(5);
    ListNode* fifth = new ListNode(11);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    KInverse so;
    ListNode* newnode = so.inverse(head, 2);
    print(newnode);
}
