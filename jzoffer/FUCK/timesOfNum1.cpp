#include <iostream>
#include <vector>
#include <math>
 
using namespace std;
//1出现在最高位和1出现在除最高位之外其他位次数
int TimesOfNum1(int n)
{
    if(n == 0)
    {
        return 0;
    }
    int highDigitNum;  //最高位数字
    int digitNums = DigitNum(n, highDigitNum); //位数
    if(digitNums == 1)
    {
        return 1;
    }
    int next = n - highDigitNum * pow(10, digitNums);  //去掉最高的数
    int highDigitTimes = (highDigitNum - 1) * pow(10, digitNums) + next + 1; //最高位1次数
    int otherDigitTimes = highDigitNum * pow(10, digitNums - 2) * (digitNums - 1);  //1出现在除去最高位之外的次数 
    int curTimes = highDigitTimes + otherDigitTimes;
    curTimes += TimesOfNum1(next);
    return curTimes;

}

int DigitNum(int n, int& highDigitNum)
{
    int count = 0;
    while(n)
    {
        ++count;
        highDigitNum = n;
        n /= 10;
    }
    return count;
}
