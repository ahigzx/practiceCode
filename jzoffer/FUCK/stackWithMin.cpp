#include <iostream>
#include <stack>

using namespace std;

template <class T>
class StackWithMin
{
    public:
        void pop();
        void push(T& member);
        T& Top();
        T& min();
        
    private:
        stack<T> nomalStack;
        stack<T> minStack;
};

template <class T>
void StackWithMin<T>::pop()
{
    assert(nomalStack.size() > 0 && minStack.size() > 0);

    nomalStack.pop();
    minStack.pop();
}

template <class T>
T &StackWithMin<T>::top()
{
    assert(nomalStack.size() > 0 && minStack.size() > 0);
    return nomalStack.top();
}

template <class T>
T &StackWithMin<T>::min()
{
    assert(nomalStack.size() > 0 && minStack.size() > 0);

    return minStack.top();
}

template <class T>
void StackWithMin<T>::push(T& member);
{
    nomalStack.push(member);
    if(nomalStack.size() == 0 || minStack.top() < member)
    {
        minStack.push(member);
    }
    else
    {
        minStack.push(minStack.top());
    }
}
