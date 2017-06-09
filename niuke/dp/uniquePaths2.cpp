class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if(obstacleGrid.empty())
                return 0;
            int n = obstacleGrid.size();
            int m = obstacleGrid[0].size();
            vector<vector<int>> paths(n, vector<int>(m, 0));
            for(int i = 0; i < m; i++)
            {
                if(obstacleGrid[0][i] == 1)
                {
                    break;
                }
                paths[0][i] = 1;
            }
            for(int i = 0; i < n; i++)
            {
                if(obstacleGrid[i][0] == 1)
                {
                    break;
                }
                paths[i][0] = 1;
            }

            if(m > 1 && n > 1)
            {
                for(int i = 1; i < m; i++)
                {
                    for(int j = 1; j < n; j++)
                    {
                        if(obstacleGrid[i][j] == 1)
                        {
                            paths[i][j] = 0;
                        }
                        else
                        {
                            paths[i][j] = paths[i-1][j] + paths[i][j-1];
                        }
                    }
                }
            }
            return paths[n-1][m-1];
        }

};
