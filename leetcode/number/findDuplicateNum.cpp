#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
        int findDuplicate(vector<int>& nums) {
            int length = nums.size();
            int min = 0;
            int max = length - 1;
            while(min <= max)
            {
                int mid = (max - min) / 2 + min;
                int count = 0;
                for(int i = 0; i < length; i++) //每次都全部遍历看小于等于Mid的个数
                {
                    if(nums[i] <= mid)
                    {
                        ++count;
                    }
                }
                if(count > mid) //全部数字中小于等于mid的个数如不重复应该是mid
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid + 1;
                }
            }
            return min;
        }

}
