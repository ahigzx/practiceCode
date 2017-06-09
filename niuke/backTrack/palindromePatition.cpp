class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> sub;
            if(!s.empty())
            {
                dfs(s, res, sub, 0);
            }
            return res;
        }
        
        void dfs(string& s, vector<vector<string>>& res, vector<string> sub, int index)
        {
            if(index == s.size())
            {
                res.push_back(sub);
                return;
            }
            for(int i = index; i < s.size(); i++)
            {
                if(isPalindrome(s, index, i))
                {
                    sub.push_back(s.substr(index, i-index+1));
                    dfs(s, res, sub, i+1); //注意这里是i+1不是Index+1
                    sub.pop_back();
                }
            }
            
        }

        bool isPalindrome(const string& str, int start, int end)
        {
            while(start < end)
            {
                if(str[start++] != str[end--])
                {
                    return false;
                }
            }
            return true;
        }
};
