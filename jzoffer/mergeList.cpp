#include <iostream>

using namespace std;


typedef struct listNode
{
    int m_data;
    struct listNode m_pnext;
}listNode,*plist;


plist mergeList(plist phead1, plist phead2)
{
    if(phead1 == NULL)
    {
        return phead2;
    }
    else if(phead2 == NULL)
    {
        return phead1;
    }

    plist mergeHead = new listNode;
    plist mergetail = mergeHead;
    while(phead1 != NULL && phead2 != NULL)
    {
        if(phead1->m_data < phead2->m_data)
        {
            mergetail->m_pnext = phead1;
            phead1 = phead1->m_pnext;
        }
        else
        {
            mergetail->m_pnext = phead2;
            phead2 = phead2->m_pnext;
        }
        mergetail = mergetail->m_pnext;
    }

    if(phead1 != NULL)
    {
        mergetail->m_pnext = phead1;
    }
    else if(phead2 != NULL)
    {
        mergetail->m_pnext = phead2;
    }
    plist merge = mergeHead->m_pnext;
    delete mergeHead;
    return merge;
}
