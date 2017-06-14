#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* m_next;
    int m_nkey;
};


ListNode* findFirstCommonNode(ListNode* first, ListNode* second)
{
    if(first == NULL || second == NULL)
        return NULL;
    int firstLen = 0;
    int secondLen = 0;
    ListNode* nodeindex = first;
    ListNode* ahead;
    ListNode* behind;
    while(nodeindex != NULL)
    {
        nodeindex = nodeindex->m_next;
        ++firstLen;
    }
    nodeindex = second;
    while(nodeindex != NULL)
    {
        nodeindex = nodeindex->m_next;
        ++secondLen;
    }
    ahead = (firstLen > secondLen) ? first : second;
    int lenDif = (firstLen > secondLen) ? firstLen - secondLen : secondLen - firstLen;
    while(lenDif > 0)
    {
        ahead = ahead->m_next;
        --lenDif;
    }
    while(ahead != behind && (ahead != NULL)&& (behind != NULL))
    {
        ahead = ahead->m_next;
        behind = behind->m_next;
    }
    if(ahead && behind)
    {
        return ahead;
    }
    else
    {
        return NULL;
    }
}
    
int main(void)
{

}
