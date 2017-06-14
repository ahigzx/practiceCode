#include <iostream>

using namespace std;

struct ComplexListNode
{
    int val;
    ComplexListNode* pNext;
    ComplexListNode* pSibling;
};


ComplexListNode* clone(ComplexListNode* chead)
{
    if(chead == NULL)
        return NULL;
    duplicateSequenceList(chead);
    copySiblingIndex(chead);
    ComplexListNode* pClone = DevideList(chead);
    return pClone;
}

void duplicateSequenceList(ComplexListNode* chead)
{
    ComplexListNode* pNode = chead;
    while(pNode != NULL)
    {
        ComplexListNode* pCloneNode = new ComplexListNode();
        pCloneNode->data = pNode->data;
        pCloneNode->pNext = pNode->pNext;
        pCloneNode->pSibling = NULL;
        pNode->pNext = pCloneNode;
        pNode = pCloneNode->pNext;
    }
}


void copySiblingIndex(ComplexListNode* chead)
{
    ComplexListNode* pNode = chead;
    ComplexListNode* pCloneNode = NULL;
    while(pNode != NULL)
    {
        pCloneNode = pNode->pNext;
        if(pNode->pSibling != NULL)
        {
            pCloneNode->pSibling = pNode->pSibling->pNext;
        }
        pNode = pCloneNode->pNext;
    }
}


ComplexListNode* DevideList(ComplexListNode* chead)
{
    ComplexListNode* pNode = chead;
    ComplexListNode* pCloneHead = chead->pNext;
    ComplexListNode* pCloneNode = NULL;
    while(pNode != NULL)
    {
        pCloneNode = pNode->pNext;
        pNode->pNext = pCloneNode->pNext; 
        pNode = pNode->pNext;
        if(pNode != NULL)
        {
            pCloneNode->pNext = pNode->pNext;
        }
        else
        {
            pCloneNode->pNext = NULL;
        }
        pCloneNode = pCloneHead->pNext;
    }
    return pCloneHead;
}
