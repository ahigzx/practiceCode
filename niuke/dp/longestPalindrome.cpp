class Solution {
    public:
        string longestPalindrome(string s) {
            string palindrome;
            if(s.empty())
                return palindrome;
            int n = s.size();
            int maxLen = 1;
            int start = 0;
            vector<vector<int>> isPalindrome(n, vector<int>(n, 0));
            for(int i = 0; i < n; i++)
            {
                isPalindrome[i][i] = 1;
                if(i < n - 1)
                {
                    if(s[i] == s[i+1])
                    {
                        isPalindrome[i][i+1] = 1;
                        maxLen = 2;
                        start = i;
                    }
                }
            }
            if(n >= 3)
            {
                for(int i = n - 3; i >= 0; i--)
                {
                    for(int j = i + 2; j < n; j++)
                    {
                        if(s[i] == s[j])
                        {
                            isPalindrome[i][j] = isPalindrome[i+1][j-1];
                            if(isPalindrome[i][j])
                            {
                                if(maxLen < j - i + 1)
                                {
                                    maxLen = j - i + 1;
                                    start = i;
                                }
                            }
                        }
                    }
                }
            }
            //palindrome.assign(s.begin() + start, s.begin() + start + maxLen);
            if(maxLen >= 2)
            {
                palindrome = s.substring(i, maxLen);
            }
            else
            {
                palindrome += s[i];
            }
            return palindrome;

        }
};
