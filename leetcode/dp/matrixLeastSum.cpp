class MinimumPath {
    public:
        int getMin(vector<vector<int> > map, int n, int m) {
            if(map.empty() || m <= 0 || n <= 0)
                return 0;
            vector<vector<int>> leastPath;
            leastPath.resize(n);
            for(auto& row : leastPath)
            {
                row.resize(m, 0);
            }
            leastPath[0][0] = map[0][0];
            for(int i = 1; i < m; i++)
            {
                leastPath[0][i] = leastPath[0][i-1] + map[0][i];
            }
            for(int i = 1; i < n; i++)
            {
                leastPath[i][0] = leastPath[i-1][0] + map[i][0];
            }
            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    leastPath[i][j] = min(leastPath[i][j-1], leastPath[i-1][j]) + map[i][j];
                }
            }
            return leastPath[n-1][m-1];
        }

}
