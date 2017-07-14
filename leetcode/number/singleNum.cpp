class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            vector<int> bit(32);
            int res = 0;  
            for(int i = 0; i < 32; ++i)
            {
                for(auto num : nums)
                {
                    bit[i] += num >> i & 1;
                }
                res |= bit[i] % 3 << i;
            }
            return res;  
        }
};
