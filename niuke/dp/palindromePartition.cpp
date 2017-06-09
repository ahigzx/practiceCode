class Solution {
    public:
            int minCut(string s) {
                if(s.empty())
                    return 0;
                int n = s.size();
                vector<vector<int> isPal(n, vector<int>(n, 0));
            
                for(int i = 0; i < n; ++i)
                {
                    isPal[i][i] = 1;
                    if(s[i] == s[i+1])
                    {
                        isPal[i][i+1] = 1;
                    }
                }
                if(n > 2)
                {
                    for(int i = n - 2; i >=0; --i)
                    {
                        for(int j = i + 2; j < n; j++)
                        {
                            if(s[i] == s[j])
                            {
                                isPal[i][j] = isPal[i+1][j-1];
                            }
                        }
                    }
                }
                vector<int> min(n, 0);
                for(int i = n-2; i >= 0; --i)
                {
                    min[i] = min[i+1] + 1;
                    for(int j = i + 1; j < n; ++j)
                    {
                        if(isPal[i][j])
                        {
                            if(j == n-1)
                            {
                                min[i] = 0;
                            }
                            else if(1 + min[j+1] < min[i]) 
                            {
                                min[i] = 1 + min[j+1];
                            }
                        }
                    }
                }
                return min[0];
                
                
                
            }
};
