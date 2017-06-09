class Backpack {
    public:
        int maxValue(vector<int> w, vector<int> v, int n, int cap) {
            vector<vector<int>> maxValue;
            maxValue.resize(n + 1);
            for(auto &x : maxValue)
            {
                x.resize(cap+1, 0);
            }
            for(int i = 0; i < cap + 1; i++)
            {
                maxValue[0][i] = 0;
            }
            for(int i = 1; i < n + 1; i++)
            {
                maxValue[i][0] = 0;
            }
            for(int i = 1; i < n + 1; i++)
            {
                for(int j = 1; j < cap + 1; j++)
                {
                    if(w[i-1] > j)
                    {
                        maxValue[i][j] = maxValue[i-1][j];
                    }
                    else
                    {
                        maxValue[i][j] = max(maxValue[i-1][j], maxValue[i-1][j-w[i-1]] + v[i-1]);
                    }
                }
            }
            return maxValue[n][cap];
            
        }
};
