class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
        {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSumRow = 0;
        int maxSumColonm= 0;
        for(int i = 0; i < n; ++i)
        {
            maxSumRow += grid[0][i];
            dp[0][i] = maxSumRow;
        }
        for(int i = 0; i < n; ++i)
        {
            maxSumColonm += grid[i][0];
            dp[i][0] = maxSumColonm;
        }
        
        if(n > 1)
        {
            for(int i = 1; i < n; ++i)
            {
                for(int j = 1; j < m; ++j)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
