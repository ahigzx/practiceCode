class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.empty())
                return 0;
            vector<int> dict(256, -1);
            int n = s.size();
            int left = 0;
            int maxLen = 0;
            for(int i = 0; i < n; ++i)
            {
                if(dict[s[i]] == -1 || left < dict[s[i]])
                {
                    maxLen = max(maxLen, i - left + 1)
                }
                else
                {
                    left = dict[s[i]]; //哈希表中记录了上一次s[i]出现的位置
                }
                dict[s[i]] = i;
            }
        }
};
