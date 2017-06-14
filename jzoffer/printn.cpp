#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool Increment(char *num)
{
    int length = strlen(num);
    bool iscarry = true;
    for(int i = length - 1;i >= 0;--i)
    {
        if(iscarry)
        {
            if(i == 0 && num[i] == '9')
            {
                return true; //最高位进位了
            }
            if(num[i] != '9')
            {
                num[i] += 1;
                iscarry = false;
                break;
            }
            else
            {
                num[i] = '0';
                iscarry = true;
            }
        }
    }
    return false;
}


void PrintNum(char *num)
{
    int length = strlen(num);
    int i = 0;
    for(i = 0;i < length;++i)
    {
        if(num[i] != '0')
        {
            break;
        }
    }
    cout << num + i << endl;
}


void Print1toMaxn(unsigned int n)
{
    char *num = new char[n + 1];
    memset(num, '0', n);  //注意是'0'
    num[n] = '\0';

    while(!Increment(num))
    {
        PrintNum(num);
    }
    delete []num;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    Print1toMaxn(n);
}
