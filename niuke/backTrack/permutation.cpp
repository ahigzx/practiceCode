#include <iostream>
#include <vector>

using namespace std;

void permuta(int n, vector<int>& vec, int cur)
{
    if(cur == n + 1)
    {
        for(auto start = vec.cbegin() + 1; start != vec.cend(); start++)
        {
            cout << *start;
        }
        cout << endl;
    }
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            bool used = false;
            for(int j = 1; j <= cur; ++j)
            {
                if(i == vec[j])
                {
                    used = true;
                }
            }
            if(!used)
            {
                vec[cur] = i;
                permuta(n, vec, cur + 1);
            }
        }

    }
}

void permutation(int n)
{
    vector<int> num;
    for(int i = 0; i <= n; ++i)
    {
        num.push_back(0);
    }
    int cur = 1;
    permuta(n, num, cur); //num用于保存一个打印序列,而不是数字集合,go to hell
}

int main(int argc, char **argv)
{
    int n = 3;
    permutation(n);
}

