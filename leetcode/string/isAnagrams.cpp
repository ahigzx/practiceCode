#include <string>
#include <cstring>

using namespace std;

class Solution {

    public:
        bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false;
            int cmp[26] = {0};
            for(int i=0;i<s.size();i++)
            {
                cmp[s[i]-'a']++;
                cmp[t[i]-'a']--;

            }
            for(int j=0;j<26;j++)
            {

                if(cmp[j] != 0) return false;

            }
            return true;
        }

}
