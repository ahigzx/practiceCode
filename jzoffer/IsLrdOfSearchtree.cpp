#include <iostream>

using namespace std;

bool IsLrdOfSearchtree(int *array, int num)
{
    if(array == nullptr|| num < 0)
    {
        return false;
    }
    if(num <= 2)
    {
        return true;
    }
    int root = array[num - 1];
    int leftstart = 0;
    int leftend = num - 1; //没找到比root大的就是最后
    int rightstart = 0;
    int rightend = num - 1;
    for(int i = 0;i < num; ++i)
    {
        if(array[i] > root)
        {
            leftend = i - 1;
            rightstart = i;
            break;
        }
    }

    for(int j = rightstart;j < num; ++j)
    {
        if(array[j] < root)
        {
            return false;
        }
    }
    bool IslrdLeft = true;
    bool IslrdRight = true;
    if(leftend > 0) //
    {
        IslrdLeft = IsLrdOfSearchtree(array, leftend+1);
    }
    if(leftend < num -1)
    {
        IslrdRight = IsLrdOfSearchtree(array + rightstart, num - rightstart - 1); //日了狗 num - rightstart - 1不是num -rightstart 去掉root
    }
    return IslrdLeft&IslrdRight;
    
}


int main(int argc, char *argv[])
{
    int A[7] = { 5,7,6,9,11,10,8 };
    int num = 7;
    bool result = IsLrdOfSearchtree(A, num);
    cout << result << endl;
}
