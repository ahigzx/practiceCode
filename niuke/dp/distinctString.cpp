class Solution {
    public:
        int numDistinct(string s, string t) {
            if(s.empty())
            {
                return 0;
            }
            if(t.empty())
            {
                return 1;
            }
            int n = s.size();
            int m = t.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for(int i = 0; i < n + 1; ++i)
            {
                dp[i][0] = 1;
            }
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= m; ++j)
                {
                    if(s[i-1] != t[j-1])
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //前i-1个组成前j个序列的个数加上 i-1组成j-1
                    }
                }
            }
            return dp[n][m];
            
        }
};
