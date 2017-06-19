#include <queue>

template <class T>
class CStack
{
    public:
        CStack();
        ~CStack();
        void push(const T& node);
        T pop(void);
        //T& top();  //题目这里没必要做成stl中top()形式，如果需要可以加入state状态表示栈内几个状态，从哪个queue中弹出元素
    private:
        std::queue que1;
        std::queue que2;
}

template <class T>
void CStack<T>::push(const T& node)
{
    if(!que2.empty())
    {
        que2.push(node);
    }
    else  //两个为空和que1不为空时均插入que1
    {
        que1.push(node);
    }
}

template <class T>
T CStack<T>::pop(void)
{
    T tempnode;
    if(que1.empty()&&que2.empty())
    {
        throw std::exception("empty stack");
    }
    if(!que2.empty)
    {
        while(que2.size()!=0)
        {
            //que1.push(que2.front());  //不知道是否有问题 front操作应该返回的是队列首部的元素的引用 这样插入pop操作如果是把该节点的空间释放掉那就可能有问题
            //que2.pop();
            
#if 1//这样需要实例化一次，但是没问题
            tempnode = que2.front();
            if(que2.size()!=1)
            {
                que1.push(tempnode);
            }
            que2.pop();
#endif 
        }
        return tempnode;
    }
    else if(!que2.empty)
    {
        while(que1.size()!=0)
        {
            //que1.push(que2.front());  //不知道是否有问题 front操作应该返回的是队列首部的元素的引用 这样插入pop操作如果是把该节点的空间释放掉那就可能有问题
            //que2.pop();
            
#if 1//这样需要实例化一次，但是没问题
            tempnode = que1.front();
            if(que1.size()!=1)
            {
                que2.push(tempnode);
            }
            que1.pop();
#endif 
        }
        return tempnode;
    }
        
}
