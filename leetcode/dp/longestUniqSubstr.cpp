class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.empty())
                return 0;
            int n = s.size();
            vector<int> dp(n + 1);
            dp[1] = 1;
            int maxLen = 1;
            if(n > 1)
            {
                for(int i = 2; i <= n; ++i)
                {
                    int k = dp[i-1];
                    for(int j = i - 1; j > 0 && k > 0; --j, --k) //挨个对比看是否重复
                    {
                        if(s[i-1] == s[j-1])
                        {
                            dp[i] = i - j;
                            break;
                        }
                        if(j == i - dp[i-1])  
                        {
                            dp[i] = dp[i-1] + 1;
                            if(maxLen < dp[i])
                                maxLen = dp[i];
                        }
                    }
                }
            }
            return maxLen;
            
        }
};
