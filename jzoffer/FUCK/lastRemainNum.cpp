#include <list>

using namespace std;

int LastRemainNum(int n, int m)
{
    if(n < 1 || m < 1)
        return -1;
    list<int> numList;
    for(int i = 0; i < n; i++)
    {
        numList.push_back(i);
    }
    auto iter = numList.begin();
    while(numList.size() > 1)
    {
        for(int i = 1; i < m; i++)
        {
            ++iter;
            if(iter == numList.end())
            {
                iter = numList.begin();
            }
        }
        iter = numList.erase(iter);
        if(iter == numList.end())
        {
            iter = numList.begin();
        }
    }
    return *numList.begin();
}


int LastRemain(int n, int m)
{

}

int main()
{

}
