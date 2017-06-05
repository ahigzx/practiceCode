#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
    int findKthLargest(vector<int>& nums, int k)
    {
        multiset<int> topk;
        for(auto num : nums)
        {
            if(nums.size() < k)
            {
                topk.insert(num);
            }
            else
            {
                if(num > *nums.begin())
                {
                    topk.erase(nums.begin());
                    topk.insert(num);
                }
            }
        }
        return *topk.begin();
    }
};
