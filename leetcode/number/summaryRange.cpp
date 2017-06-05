#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {

    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> ranges;
            int start;
            int end;
            start = end = nums[0];
            int n = nums.size();
            if(n > 1)
            {
                for(int i = 1; i < n; ++i)
                {
                    if(nums[i] == nums[i-1] + 1)
                    {
                        ++end;
                    }
                    else
                    {
                        if(start == end)
                        {
                            char numsRange[10];
                            sprintf(numsRange, "%d", start);
                            ranges.push_back(string(numsRange));
                        }
                        else
                        {
                            char numsRange[22];
                            sprintf(numsRange, "%d->%d", start, end);
                            ranges.push_back(string(numsRange));
                        }
                        start = end = nums[i];
                    }
                }
            }
            if(start == end)
            {
                char numsRange[10];
                sprintf(numsRange, "%d", start);
                ranges.push_back(string(numsRange));
            }
            else
            {
                char numsRange[22];
                sprintf(numsRange, "%d->%d", start, end);
                ranges.push_back(string(numsRange));
            }
            
            return ranges;
        }

};

int main(void)
{

}
