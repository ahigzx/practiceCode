class Solution {
    public:
        int jump(vector<int>& nums) {
            if(nums.empty())
                return 0;
            int n = nums.size();
            int step = 0;
            if(n == 1)
                return 0;
            if(0 + nums[0] >= n - 1)
                return step + 1;
            for(int i = 0; i < n;)
            {
                int maxidx = i;
                int maxstep = 0;
                for(int j = i + 1; j <= i + nums[i]; j++)
                {
                    if(maxstep < nums[j] + j)
                    {
                        maxstep = nums[j] + j;
                        maxidx = j;
                    }
                }
                i = maxidx;
                ++step;
                if(maxstep >= n - 1)
                    return step + 1;
            }
        }
};
