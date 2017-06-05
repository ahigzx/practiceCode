#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int maxSubArray(vector<int>& nums) {
            int len = nums.size();
            int sum = 0;
            int maxSubSum = 0x80000000;
            for(int i = 0; i < len; i++)
            {
                sum += nums[i];
                if(sum > maxSubSum)
                {
                    maxSubSum = sum;
                }
                if(sum < 0)
                {
                    sum = 0;
                }
            }
            return maxSubSum;

        }

};
