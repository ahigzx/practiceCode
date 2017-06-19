#include <iostream>
#include <vector>

using namespace std;

vector<int> getPairSums(vector<int> nums, int s)
{
    vector<int> pair;
    if(nums.empty)
        return pair;
    auto ahead = nums.end() - 1;
    auto behind = nums.begin();
    while(behind != ahead)
    {
        //int sum = *behind + *ahead;
        long long sum = *behind + *ahead; //考虑溢出
        if(sum == s)
        {
            pair.push_back(*behind);
            pair.push_back(*ahead);
        }
        else if(sum > s)
        {
            --ahead;
        }
        else if(sum < s)
        {
            ++behind;
        }
    }
    return pair;
}

vector<vector<int>> GetNumsSums(int s)
{
    vector<int> nums;
    vector<vector<int>> vec;
    int small = 1;
    int big = 2;
    int curSum = small + big;
    while(small < (1 + s) / 2 )
    {
        if(curSum == s)
        {
            for(int i = small; i <= big; i++)
            {
                Nums.push_back(i);
            }
            vec.push_back(nums);
        }
        else if(curSum < s)
        {
            curSum += ++big;
        }
        else
        {
            curSum -= small++;
            if(curSum == s)
            {
                for(int i = small; i <= big; i++)
                {
                    Nums.push_back(i);
                }
                vec.push_back(nums);
            }

        }
    }
    return vec;

}




vector<vector<int>> GetNumsSums(int s)
{
    vector<int> nums;
    vector<vector<int>> vec;
    int small = 1;
    int big = 2;
    int curSum = small + big;
    while(small < (1 + s) / 2 )
    {
        if(curSum == s)
        {
            for(int i = small; i <= big; i++)
            {
                Nums.push_back(i);
            }
            vec.push_back(nums);
        }
        while(curSum < s && small < (1 + s) / 2)
        {
            curSum -= small--;
            if(curSum == s)
            {
                for(int i = small; i <= big; i++)
                {
                    Nums.push_back(i);
                }
                vec.push_back(nums);
            }
        }

        curSum += ++big;
    }
    return vec;
}
