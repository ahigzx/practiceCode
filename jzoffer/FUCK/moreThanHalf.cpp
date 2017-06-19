#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
    void moreThanHalf(vector<int>& vec)
    {
        assert(!vec.empty());
        int number;
        int count = 0;
        number = vec[0];
        for(auto iter = vec.cbegin(); iter != vec.cend(); iter++)
        {
            if(*iter == number)
            {
                count++;
            }
            else
            {
                count--;
                if(count == 0)
                {
                    number = *iter;
                    count = 1;
                }
            }
        }
        if(CheckNum(vec, number))
        {
            cout << number << endl;
        }
    }
    
    bool CheckNum(const vector<int>& vec, int number)
    {
        int times = 0;
        bool result;
        for(auto x : vec)
        {
            if(x == number)
            {
                times++;
            }
        }
        if(times*2 < vec.size())
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    }

};

int main(void)
{

}
