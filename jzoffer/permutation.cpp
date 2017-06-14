#include <iostream>
#include <vector>


using namespace std;

class solution
{
    void permutation(const string& s)
    {
        if(str.empty())
            return;
        int cur = 0;
        string str(s);
        int n = str.size();
        permut(n, str, cur);
    }
    void permut(int n, string& str, int cur)
    {
        if(cur == n)
        {
            cout << str << endl;
        }
        else
        {
            for(int i = cur; i < n; ++i)
            {
                if(i == cur || str[i] ==  str[cur])
                    continue;
                swap(str[cur],str[i]);
                permut(n, str, cur + 1);
                swap(str[cur],str[i]);
            }
        }
    }
}
