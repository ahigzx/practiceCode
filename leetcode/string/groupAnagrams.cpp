#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {

    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> group;
            unordered_map<string,vector<string>> hash_map;
            for(auto str : strs)
            {
                string temp(str);
                sort(temp.begin(), temp.end());
                hash_map[temp].push_back(str);
            }
            for(auto vecString : hash_map)
            {
                group.push_back(vecString.second);
            }
            return group;

        }

};
