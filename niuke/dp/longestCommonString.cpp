#include <iostream>
#include <string>

class LCS {
    public:
        int findLCS(string A, int n, string B, int m) {
            if(A.empty() || n <= 0 || B.empty() || m <= 0)
                return 0;
            vector<vector<int>> maxLen;
            maxLen.resize(n + 1);
            for(auto &x : maxLen)
            {
                x.resize(m + 1);
            }
            for(int i = 0; i < m + 1; i++)
            {
                maxLen[0][i] = 0;
            }
            for(int i = 1; i < n + 1; i++)
            {
                maxLen[i][0] = 0;
            }
            for(int i = 1; i < n + 1; i++)
            {
                for(int j = 1; j < m + 1; ++j)
                {
                    if(A[i-1] == B[j-1])  //多一行一列所以i的值表示第几个字符,需要-1表示A[i]
                    {
                        maxLen[i][j] = maxLen[i-1][j-1] + 1;
                    }
                    else
                    {
                        maxLen[i][j] = max(maxLen[i][j-1], maxLen[i-1][j]);
                    }
                }
            }
            return maxLen[n][m];
            
        }
};
