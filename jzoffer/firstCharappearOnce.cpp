#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char findOnceChar(string str)
{
    unordered_map<char, int> charNum_map;
    for(char x : str)
    {
        ++charNum_map[x];
    }

    for(char c : str)
    {
        if(charNum_map[c] == 1)
        {
            return c;
        }
    }
    return -1;
}

int main(void)
{

}

