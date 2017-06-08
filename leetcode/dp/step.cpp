#include <iostream>
#include <vector>

using namespace std;

class GoUpstairs {
    public:
        int countWays(int n) {
            vector<int> ways(n+1, 0);
            ways[0] = 1;
            ways[1] = 1;
            ways[2] = 2;
            for(int i = 3; i < n + 1; i++)
            {
                ways[i] = ways[i-1] + ways[i-2];
            }
            return ways[n];
        }
};
