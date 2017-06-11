class Prior {
    public:
        string findSmallest(vector<string> strs, int n) {
            if(n <= 0 || strs.empty())
                return NULL;
            sort(strs.begin(), strs.end(), [](const string& str1, const string& str2){return str1 + str2 < str2 + str1;});
            string res;
            for(auto& str : strs)
            {
                res += str;
            }
            return res;
        }
};
