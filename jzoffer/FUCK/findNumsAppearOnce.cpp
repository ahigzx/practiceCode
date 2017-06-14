#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindFirstBit1(int num)
{
    int indexOf1bit = 0;
    if(num)
    {
        while((num & 1 == 0) && indexOf1bit < sizeof(int) * 8)
        {
           num = num >> 1; 
           ++indexOf1bit;
        }
    }
    else
    {
        indexOf1bit = -1;
    }
    return indexOf1bit;
}


vector<int> FindNumsAppearOnce(vector<int> nums)
{
    int exclusiveOr = 0;
    vector<int> twoOnceNums;
    int firstNum;
    int secondNum;
    for(auto num : nums)
    {
        exclusiveOr ^= num;
    }
    int first1bitPos = FindFirstBit1(exclusiveOr);

    auto index = partition(nums.begin(), nums.end(),
            [first1bitPos](const int obj)->bool{obj >> first1bitPos; return (obj & 1);});

    for(auto iter = nums.begin(); iter != index; iter++)
    {
        firstNum ^= *iter;
    }
    twoOnceNums.push_back(firstNum);
    for(auto iter = index; iter != nums.end(); iter++)
    {
        secondNum ^= *iter;
    }
    twoOnceNums.push_back(secondNum);
    return twoOnceNums;

}

bool IsBit1(int num, int firstBit1)
{
    num = num >> firstBit1;
    return (num & 1);
}

vector<int> FindNumsAppearOnce1(vector<int> nums)
{
    int exclusiveOr = 0;
    vector<int> twoOnceNums;
    int firstNum;
    int secondNum;
    for(auto num : nums)
    {
        exclusiveOr ^= num;
    }
    int first1bitPos = FindFirstBit1(exclusiveOr);

    for(auto num : nums)
    {
        if(IsBit1(num, first1bitPos))
        {
            firstNum ^= num;
        }
        else
        {
            secondNum ^= num;
        }
    }
    twoOnceNums.push_back(firstNum);
    twoOnceNums.push_back(secondNum);
    return twoOnceNums;

}


int main(void)
{

}
