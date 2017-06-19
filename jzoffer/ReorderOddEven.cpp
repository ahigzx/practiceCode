#include <iostream>
#include <algorithm>

using namespace std;

void ReorderOddEven(int *array, int num)
{
    if(array == NULL || num < 0)
    {
        return;
    }
    int Oddpart = -1; //Oddpart表示奇数那一半的划分

    for(int i = 0; i < num; ++i)
    {
        if(array[i]&0x1 == 1) 
        {
            ++Oddpart;
            if(i != Oddpart) 
            {
                swap(array[Oddpart], array[i]);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    int array[] = {
        1,2,3,4,5,6,7,8,9,0
    };
    int num = sizeof(array)/sizeof(int);

    ReorderOddEven(array, num);
    for(int i = 0; i < num; ++i)
    {
        cout << array[i] << ' ';
    }
    cout << endl;

}
