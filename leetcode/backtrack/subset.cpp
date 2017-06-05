#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

    public:
            vector<vector<int>> subsets(vector<int>& nums) {
                vector<vector<int>> subs;
                if(nums.empty())
                {
                    return subs;
                }
                vector<int> selected(nums.size());
                getSubset(nums, subs, selected, 0);
                return subs;

            }

            void getSubset(vector<int>& nums, vector<vector<int>>&subs, vector<int>&selected,  int t)
            {
                vector<int> subtemp;
                int n = nums.size();
                if(t == n)
                {
                    for(int i = 0; i < n; i++)
                    {
                        if(selected[i])
                        {
                            subtemp.push_back(nums[i]);
                        }
                    }
                    subs.push_back(subtemp);
                    return;
                }

                for(int i = 0; i < 2; ++i)
                {
                    selected[t] = i;
                    getSubset(nums, subs, selected, t+1);
                }
            }

};


int main(void)
{

}
