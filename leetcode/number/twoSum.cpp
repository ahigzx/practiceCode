class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> twoNum;
            unordered_map<int, int> minusNum;
            int len = nums.size();
            for(int i = 0; i < len; i++)
            {
                if(minusNum.find(nums[i]) != minusNum.end())
                {
                    twoNum.push_back(i);
                    twoSum.push_back(minusNum[nums[i]]);
                    return twoNum;
                }
                else
                {
                    minusNum[target - nums[i]] = i;
                }
            }
            return twoNum;
        }
};
