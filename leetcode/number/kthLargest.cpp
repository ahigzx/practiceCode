#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


class Solution {

    public:
        int findKthLargest(vector<int>& nums, int k) {
            
            int start = 0;
            int end = nums.size() - 1;
            return KthLargest(nums, start, end, k);

        }
        int randInRange(int begin, int end)
        {
            if(end == begin)
                return begin;
            srand(time(0));
            return rand() % (end - begin) + begin;
        }
        int KthLargest(vector<int>& nums, int start, int end, int k)
        {
            int pos = randInRange(start, end);
            auto iter = partition(nums.begin() + start, nums.begin() + end, [pos, nums](const int mem)->bool{return mem <= nums[pos];});
            int size = iter - nums.begin() - start;
            if(size + 1 == k)
            {
                return *iter;
            }
            else if(size + 1 < k)
            {
                int newstart = size + 1;
                int newend = nums.size() - 1;
                return KthLargest(nums, newstart, newend, k - size - 1);
            }
            else
            {
                int newstart = 0;
                int newend = size - 1;
                return KthLargest(nums, newstart, newend, k);
            }
        }

};

int main(void)
{
    vector<int> vec{
        2,1,3,4,5
    };
    //int num;
    int k = 4;
#if 0
    cin >> k;
    while(cin >> num)
    {
        vec.push_back(num);
    }
#endif
    Solution so;
    int result = so.findKthLargest(vec, k);
    cout << result << endl;

}
