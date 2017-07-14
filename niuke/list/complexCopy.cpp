#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
        }
};

class Solution {
    public:
        RandomListNode* Clone(RandomListNode* pHead)
        {
            if(pHead == NULL)
                return NULL;
            RandomListNode* cur = pHead;
            RandomListNode* next = NULL;
            while(cur != NULL)
            {
                next = cur->next;
                RandomListNode* newNode = new RandomListNode(cur->label);
                cur->next = newNode;
                newNode->next = next;
                cur = next;
            }

            cur = pHead;
            RandomListNode* index = NULL;
            while(cur != NULL)
            {
                index = cur->next;
                if(cur->random != NULL)
                    index->random = cur->random->next;
                cur = index->next;
            }

            RandomListNode* newHead = pHead->next;
            cur = pHead;
            while(cur != NULL)
            {

                index = cur->next;
                cur->next = index->next;
                cur = cur->next;
                if(cur != NULL)
                    index->next = cur->next;

            }   
            return newHead;
        }
};


int main(void)
{
    RandomListNode* Node1 = new RandomListNode(1);
    RandomListNode* Node2 = new RandomListNode(2);
    RandomListNode* Node3 = new RandomListNode(3);
    Node1->next = Node2;
    Node2->next = Node3;
    Node1->random = Node3;
    Solution so;
    RandomListNode* newhead = so.Clone(Node1);
    cout << 1 << endl;
}
