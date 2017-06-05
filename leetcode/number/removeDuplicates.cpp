#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.empty())
                return 0;
            int n = nums.size();
            int count;
            if(n > 1)
            {
                for(int i = 1; i < n; ++i)
                {
                    if(nums[i] == nums[i-1])
                    {
                        ++count;
                    }
                    else
                    {
                        nums[i-count] = nums[i];
                    }
                }
                return n - count;
            }
        }

};
