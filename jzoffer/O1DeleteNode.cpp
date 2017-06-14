#include <iostream>
#include <cstdlib>

typedef struct listNode
{
    int m_data;
    struct listNode m_pnext;
}listNode,*plist;


plist Deletenode(plist* list, plist list_index)
{
    if(list == NULL || *list == NULL || list_index == NULL)
    {
        return NULL;
    }

    plist pnext == NULL;
    if(*list == list_index)
    {
        free(list_index);
        *list = NULL;
        list_index = NULL;
    }
    else if(list_index->m_pnext == NULL) //如果是尾节点还需注意从头开始遍历删除
    {
        //free(list_index);
        //list_index = NULL;
        ptemp = *list;
        while(ptemp->m_pnext != list_index)
        {
            ptemp = ptemp->m_pnext;
        }
        ptemp->m_pnext = NULL;
        free(list_index);
        list_index = NULL;
        
    }
    else
    {
        pnext = list_index->m_pnext;
        list_index->m_data = pnext->m_data;
        list_index->m_pnext = pnext->m_pnext;
        free(pnext);
        pnext = NULL;
    }
    return *list;
}
