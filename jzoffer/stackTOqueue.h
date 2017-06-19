#include <stack>


template <typename T>
class cQueue
{
    public:
        cQueue(void);
        ~cQueue(void);
        void appendTail(const T& node); //插入
        T deleteHead();  //弹出

    private:
        std::stack<T> stk1;
        std::stack<T> stk2;
};

template <class T>
void cQueue<T>::appendTail(const T& node)
{
    stk1.push(node);
}

template <class T>
T cQueue<T>::deleteHead()
{
    T tempnode;
    if(stk2.empty()&&stk1.empty())
    {
        throw std::exception("invalid operation:the queue is empty");
    }
    else
    {
        if(stk2.empty())
        {
            while(!stk1.empty())
            {
                tempnode = stk1.top();
                stk1.pop();
                stk2.push(tempnode);
            }
        }
        tempnode = stk2.top();
        stk2.pop();
        return tempnode;
    }
}
