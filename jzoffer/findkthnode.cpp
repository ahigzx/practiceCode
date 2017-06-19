#include <iostream>

using namespace std;

typedef struct listNode
{
    int m_data;
    struct listNode m_pnext;
}listnode,*plist;

plist findTthFromTail(plist plisthead, int k)
{
    if(plisthead == NULL || k <= 0)
    {
        return NULL;
    }
    plist pahead = plisthead;
    plist pbehind = plisthead;
#if 0
    while(pbehind != NULL)
    {
        ++count;
        if(pbehind->m_pnext == NULL && count < k)
        {
            return NULL;
        }
        if(count = k-1)
        {
            pahead = plisthead;
        }

        pbehind = pbehind->m_pnext;
        if(count > k-1)
        {
            pahead = pahead->m_pnext;
        }
    }
#endif
    for(int i = 0; i < k-1; ++i)
    {
        if(pahead->m_pnext == NULL)
        {
            return NULL;
        }
        pahead = pahead->m_pnext;
    }

    while(pahead != NULL)
    {
        pahead = pahead->m_pnext;
        pbehind = pbehind->m_pnext;
    }
    return pahead;
}
