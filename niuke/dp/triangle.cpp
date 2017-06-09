class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            if(triangle.empty())
            {
                return 0;
            }
            int n = triangle.size();
            int minSum[n];
            for(int i = 0; i < n; i++)
            {
                minSum[i] = triangle[n-1][i];
            }
            if(n > 1)
            {
                for(int i = n-2; i >= 0; i--)
                {
                    for(int j = 0; j <= i; j++)
                    {
                        minSum[j] = min(minSum[j], minSum[j+1]) + triangle[i][j];
                    }
                }
            }
            return minSum[0];
        }
};
