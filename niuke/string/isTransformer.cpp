#include <iostream>
#include <unordered_map>
using namespace std;
class Transform {
    public:
            bool chkTransform(string A, int lena, string B, int lenb) {
                if(lena != lenb)
                    return false;
                unordered_map<char, int> Amap;
                unordered_map<char, int> Bmap;
                for(auto& x : A)
                {
                    ++Amap[x];
                }

                for(auto& x : B)
                {
                    ++Bmap[x];
                }

                if(Amap.size() != Bmap.size())
                    return false;

                for(auto& p : Amap)
                {
                    auto iter = Bmap.find(p.first);
                    if((iter != Bmap.end()) && (*iter).second == p.second)
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                return true;
            }
};

int main(void)
{

}
