class Solution {
    public:
        int numDecodings(string s) {
            if(s.empty())
                return 0;
            int n = s.size();
            vector<int> dp(n);
            if(s[0] == '0')
                return 0;
            for(int i = 0; i < n - 1; i++)
            {
                if((s[i] > '2' || s[i] == '0')&& s[i+1] == '0')
                    return 0;
            }
            dp[0] = 1;
            if(s[0] == '1' && s[1] != '0' || (s[0] == '2' && s[1] <= '6' && s[1] != '0'))
                dp[1] = 2;
            else
                dp[1] = 1;
            for(int i = 2; i < n; i++)
            {
                if(s[i] == '0')
                {
                    dp[i] = dp[i-2];
                }
                else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
                {
                    dp[i] = dp[i-2] + dp[i-1];
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            return dp[n-1];
        }

};
