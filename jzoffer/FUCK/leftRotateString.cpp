#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string LeftRotateString(string str,unsigned int num)
{
    unsigned int length = str.size();
    if(length && num > 0)
    {
        unsigned int index = num % length;
        if(index == 0)
            return str;
        reverse(str.begin(), str.end());
        auto mid = str.end() - index;
        reverse(str.begin(), mid);
        reverse(mid, str.end());
    }
    return str;
    
}
