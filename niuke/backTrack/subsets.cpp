class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int>> res;
            vector<int> sub;
            if(!S.empty())
            {
                dfs(S, res, sub, 0);
            }
            return res;
        }
        void dfs(vector<int>& s, vector<vector<int>>& res, vector<int> sub, int t) //sub不能传引用，上个函数的改变会对sub造成变化
        {
            if(t == s.size())
            {
                res.push_back(sub);
                return;
            }
            dfs(s, res, sub, t+1);
            sub.push_back(s[t]);
            dfs(s, res, sub, t+1);
        }
};
