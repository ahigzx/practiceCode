class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.empty())
                return false;
            if(nums.size() == 1)
                return true;
            int n = nums.size();
            if(nums[0] >= n - 1)
                return true;
            int maxStep = 0;
            int maxIdx = 0;
            for(int i = 0; i < n;)
            {
                for(int j = i + 1; j <= i + nums[i]; ++j)
                {
                    if(j + nums[j] >= n - 1)
                        return true;
                    else
                    {
                        if(maxStep < j + nums[j])
                        {
                            maxStep = j + nums[j];
                            maxIdx = j;
                        }
                    }
                }
                if(i == maxIdx)
                    return false;
                i = maxIdx;
            }
            return false;
        }
};
