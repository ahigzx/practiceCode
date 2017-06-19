#include <iostream>

using namespace std;

void printnumbersInCircle(int **numbers, int rows, int columns, int start)  //边界判断画图可以确保正确
{
    if(numbers == NULL || rows < 0 || columns < 0 || start < 0)
        return;

    //int endX = columns - 1 - start;
    //int endY = rows - 1 - start;  以免繁琐可以先声明变量
    for(int i = start; i < columns - start; ++i)
    {
        cout << numbers[start][i] << " ";
    }

    if(rows - start - 1 > start)
    {
        for(int j = start + 1; j < rows - start; ++j)
        {
            cout << numbers[j][columns - start - 1] << " ";
        }
    }

    if(columns - start - 1 > start)
    {
        for(int h = columns - start -1; h >= start; --h)
        {
            cout << numbers[rows - start - 1][h] << " ";
        }
    }
        

    if(rows - start - 2 > start && columns - start - 1 > start)
    {
        for(int k = rows - start - 2; k > start; --k)
        {
            cout << numbers[k][start] << " ";
        }
    }
    cout << endl;
}

void PrintnumbersClockwisely(int **numbers, int rows, int columns)  
{
    if(numbers == NULL || rows < 0 || columns < 0)
        return;

    int start = 0;
    
    while(rows > start*2 && columns > start*2)
    {
        printnumbersInCircle(numbers , rows, columns, start);
        ++start;
    }
}


int main()
{

}
