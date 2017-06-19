#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

string num2str(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

string itostring(int i)
{
    char str[10];
    sprintf(str, "%d", i);
    return string(str);
}


void printMinNum(vector<int> vec)
{
    vector<string> Vstr;
    for(auto x : vec)
    {
        string temp = itostring(x);
        Vstr.push_back(temp);
    }

    sort(Vstr.begin(), Vstr.end(), [](const string& str1, const string& str2)->bool{ string A = str1 + str2; string B = str2 + str1; return A < B;});

    for(auto str : Vstr)
    {
        cout << str;
    }
    cout << endl;
}

int main(void)
{
    vector<int> vec{
        3,32,321
    };

    printMinNum(vec);
}
