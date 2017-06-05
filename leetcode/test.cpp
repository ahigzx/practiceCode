#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;
int randInRange(int begin, int end)
{
    srand(time(0));
    return rand() % (end - begin) + begin;
}
int main(void)
{
    vector<int> vec{
       5,2,
    };
    cout << "begin:" << endl;
    for(auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    int pos = 1; 

    auto iter = partition(vec.begin(), vec.end(), [pos, vec](const int& mem)->bool{return mem < vec[pos];});

    //auto iter = partition(vec.begin(), vec.end(), [](const int& mem){return mem < 4;});

    cout << "end:" << endl;

    for(auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}
