#include <iostream>
#include <stack>

using namespace std;

int findNUM(int *array, int nlength, int val)
{
    for(int i = 0; i < nlength; ++i)
    {
        if(array[i] == val)
            return i;
    }
    return -1;
}
bool IsPopSequenceOfstack(int *pushSequece, int *popSequence, int nlength)
{
    if(pushSequece == NULL || popSequence == NULL || nlength <= 0)
        return false;
    stack<int> stk;

    int start = -1;
    int index;
    for(int i = 0; i < nlength; ++i)
    {
        index = findNUM(pushSequece, nlength, popSequence[i]);

        if(index > start)  //start表示start之前的数以压入过栈中
        {
            for(int j = start + 1; j <= index; ++j)
            {
                stk.push(pushSequece[j]);
            }
            stk.pop();
            start = index;
        }
        else
        {
            if(stk.top() != popSequence[i])
            {
                return false;
            }
            else
            {
                stk.pop();
                continue;
            }
        }
    }
    return true;
}


int main(int argc, char **argv)
{
    int a[] = {1,2,3,4,5};
    int b[] = {4,5,3,2,1};
    int c[] = {4,3,5,1,2};
    bool result = IsPopSequenceOfstack(a, b, 5);
    cout << result << endl;
    bool result1 = IsPopSequenceOfstack(a, c, 5);
    cout << result1 << endl;
}
