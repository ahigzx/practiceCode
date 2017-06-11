class Parenthesis {
    public:
        bool chkParenthesis(string A, int n) {
            if(n == 0 || A.empty())
                return false;
            int num = 0;
            for(auto& x : A)
            {
                if(x != '(' && x != ')')
                    return false;
                if(x == '(')
                {
                    ++num;
                }
                else
                {
                    --num;
                }
            }
            if(num == 0)
                return true;
            else
                return false;
        }
};
