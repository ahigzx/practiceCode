#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
            string longestCommonPrefix(vector<string>& strs) {
                string prefix;
                if(strs.empty())
                    return prefix;
                int maxLen = 0;
                for(auto& str : strs)
                {
                    maxLen = (maxLen > str.size()) ? maxLen : str.size();
                }
                for(int i = 0; i < maxLen; i++)
                {
                    char c = strs[0][i];
                    bool isPre = true;
                    for(auto& str : strs)
                    {
                        if(c != str[i])
                        {
                            isPre = false;
                            break;
                        }
                    }
                    if(isPre)
                    {
                        prefix.push_back(c);
                    }
                    else
                    {
                        return prefix;
                    }
                }
                return prefix;
            }
}
