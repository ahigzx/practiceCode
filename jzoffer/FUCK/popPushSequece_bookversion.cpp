#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(const int* pPush, const int* pPop, int nlength)
{
    if(pPush == NULL || pPop == NULL || nlength <= 0)
    {
        return false;
    }
    
    const int* pNextPush = pPush;  //
    const int* pNextPop = pPop;    //下个弹出的元素
    bool bPossible = false;

    while(pNextPop - pPop < nlength) 
    {
        stack<int> stk;
#if 0
        if(stk.size() == 0 || stk.top() != *pNextPop)
        {
            while(pNextPush != *pNextPop)
            {
                stk.push(*pNextPush);
                pNextPush++;
            }
        }
#endif
        
        while(stk.size() == 0 || stk.top() != *pNextPop)  //插入直到与要弹出的数相等，如找不到相等说明到了末尾，即需要弹出的数在栈中，所以该序列不是弹出序列
        {
            if(pNextPush - pPush == nlength) //插入序列已到末尾 
                break;

            stk.push(*pNextPush);
            pNextPush++;
        }
        
        if(stk.top() != *pNextPop)
        {
            break;
        }
        else
        {
            stk.pop();
            pNextPush++;
        }
    }
    if(stk.empty() && pNextPop - pPop == nlength)
        bPossible = true;

    return bPossible;
}
