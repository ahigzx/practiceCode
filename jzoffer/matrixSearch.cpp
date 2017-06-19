#include <iostream>

using namespace std;

bool find(int *matrix, int row, int column, int number)
{
    if(matrix == NULL ||row < 0 || column < 0)
        return false;
    int i , j; 
    i = 0;
    j = column - 1;
    while(i < row && j >= 0)
    {
        if(*(matrix + i * column + j) > number)
        {
            --j;
        }
        else if(*(matrix + i * column + j) < number)
        {
            ++i;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int a[][3] = { 0,1,2,3,4,5,6,7,8,9,10,11};
    //int *matrix = (int*)a;

    if(find((int *)a, 3, 4 ,10))
    {
        cout << "found" << endl;
    }
}
