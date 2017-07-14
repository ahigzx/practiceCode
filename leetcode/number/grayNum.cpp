class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res;
            if(n == 0)
                return res;
            res.reserve(pow(2,n));
            bitset<n> bit;
            dfs(bit, res, 0, n);
            return res;
        }
        void dfs(bitset<n>& bit, vector<int>& res, int k, int n)
        {
            if(k == n)
            {
                res.push_back(static_cast<int> bit.to_ulong());
                return;
            }
            dfs(bit, res, k+1, n);
            bit.flip(k);
            dfs(bit, res, k+1, n);
        }
};
