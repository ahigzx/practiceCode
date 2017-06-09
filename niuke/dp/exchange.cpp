#include <iostream>
#include <vector>

using namespace std;

class Exchange {
    public:
        int countWays(vector<int> penny, int n, int aim) {
            int ret;
            if(penny.empty() || n < 0 || aim < 0)
                return 0;

            vector<vector<int>> count;
            countWays.resize(n);
            for(auto &row : count)
            {
                row.resize(aim + 1, 0);
            }
            for(int i = 0; i < size; i++)
            {
               count[i][0] = 1;
            }
            for(int i = 1; i * penny[0] <= aim; i++)
            {
                count[0][i * penny[0]] = 1;
            }
            for(int i = 1; i < n - 1; i++)
            {
                for(int j = 1; j <= aim; j++)
                {
                    //count[i][j] = count[i][j-penny[i]] + count[i-1][j];
                    for(int k = 0; k * penny[i] <= j; k++)
                    {
                        count[i][j] += count[i-1][j-k*penny[i]];
                    }
                }
            }
            return count[n-1][aim];
        }

};
