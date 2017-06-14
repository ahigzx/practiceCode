#include <iostream>

using namespace std;

typedef struct listNode
{
    int m_data;
    struct listNode m_pnext;
}listNode,*plist;


plist reverseList(plist listhead)
{
    if(listhead == NULL)
    {
        return NULL;
    }

    plist prenode = listhead;
    plist pnode = NULL;
    plist nextnode = NULL;
    if(listhead->m_pnext != NULL)
    {
        pnode = listhead->m_pnext;
        listhead->next = NULL;
    }

    while(pnode!= NULL)
    {
        nextnode = pnode->next;
        pnode->m_pnext = prenode;
        prenode = pnode;
        pnode = nextnode;
    }
    return prenode;
}


plist reverseList1(plist listhead)  //如果Listhead为空逻辑上也返回NULL 无须一开始就判断
{
    plist pnode = listhead;
    plist prenode = NULL;
    plist reversehead = NULL;
    
    while(pnode != NULL)
    {
        plist pnextnode = pnode->next;
        if(pnextnode == NULL)
        {
            reversehead = pnode;
        }
        pnode->m_pnext = prenode;
        prenode = pnode;
        pnode = pnextnode;
    }
    return reversehead;
}
