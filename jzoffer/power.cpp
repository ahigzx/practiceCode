#include <iostream>

using namespace std;

double PowerWithUnsigned(double base, unsigned int exponent) 
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double result = PowerWithUnsigned(base,exponent >> 1);  
    result *= result;
    if(exponent & 0x1 == 1)
        result *= base;
    return result;
}

bool equal(double a, double b) //计算机表示小数时因为精度问题是有误差的，如果两个数相差较小则认为他们相等
{
    if((a - b <= 0.0000001)&&(b - a <= 0.0000001))
    {
        return true;
    }
    else
    {
        return false;
    }
}

double power(double base ,int exponent)
{
    if(equal(base, 0.0) && exponent < 0)
    {
        return 0.0;
    }

    unsigned int absexponent = (unsigned int)exponent;
    if(exponent< 0)
    {
        absexponent = (unsigned int)(-exponent);
    }
    double result = PowerWithUnsigned(base, absexponent);
    if(exponent < 0)
    {
        result = 1.0 / result;
    }

    return result;
}

int main(int argc, char *argv[])
{
    double base;
    int exponent;
    cin >> base;
    cin >> exponent;
    double result = power(base, exponent);
    cout << result << endl;
}
