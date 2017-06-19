#include <iostream>
#include <cstring>

using namespace std;

void printNum(char* num)
{
    if(num == NULL)
        return;
    int length = strlen(num);
    int i;
    for(i = 0; i < length; ++i)
    {
        if(num[i] != '0')
        {
            break;
        }
    }
    cout << num + i << endl;
}

void print1tomax_remain(char *num, int index)
{
    int length = strlen(num);
    if(index == length - 1)
    {
        printNum(num);
        return;
    }

    for(int i = 0; i < 10; ++i)
    {
        num[index + 1] = '0' + i;
        print1tomax_remain(num, index + 1);
    }
}
void print1tomax_recursion(int n)
{
    if(n < 0)
        return;

    char *num = new char[n + 1];
    memset(num, '0', n);
    num[n] = '\0';
    int index = 0;

    for(int i = 0; i < 10; ++i)
    {
        num[0] = '0' + i;
        print1tomax_remain(num, index);
    }
    
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    print1tomax_recursion(n);
}
