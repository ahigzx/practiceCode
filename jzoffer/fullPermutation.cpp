#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<string> Permutation(string str)
        {
            vector<string> permutation;
            if(str.empty())
            {
                return permutation;
            }
            int index = 0;
            Permutation(str, permutation, index);
            return permutation;
        }
        
        void Permutation(string str, vector<string>& vec, int index)
        {
            if(index == str.size() - 1)
                vec.push_back(str);  //递归到最后一个字母时，等于是到打解节点树的叶子结点，将该值打印
            for(int i = index; i < str.size(); ++i)
            {
                //if(str[index] != str[i])
                //{
                if(i != index && str[i] == str[index])
                    continue;

                    swap(str[index], str[i]);
                    Permutation(str, vec, index+1);
                    swap(str[index], str[i]);  //复位
                //}
            }

        }
        
};


int main(int argc, char *argv[])
{
    string a = "abcd";
    Solution so;
    vector<string> vec;
    vec = so.Permutation(a);
    for(auto mem : vec)
    {
        cout << mem << " ";
    }
    cout << endl;
    
}
