#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution
{
    int GetKthUglyNum(int k)
    {
        vector<int> uglyNum;
        uglyNum.push_back(1);
        //int nextIndex = 1;
        int MultiIdx2 = 0; //每个Idx表示当前第一个*2 3 5大于已存最大值的数的下标
        int MultiIdx3 = 0;
        int MultiIdx5 = 0;
        while(uglyNum.size() <= k) //每次往容器中加入一个丑数
        {
            int min = MinOf3Num(uglyNum[MultiIdx2]*2, uglyNum[MultiIdx3]*3, uglyNum[MultiIdx5]*5);
            uglyNum.push_back(min);
            while(uglyNum[MultiIdx2]*2 <= *uglyNum.rbegin())
                ++MultiIdx2;
            while(uglyNum[MultiIdx3]*3 <= *uglyNum.rbegin())
                ++MultiIdx3;
            while(uglyNum[MultiIdx5]*5 <= *uglyNum.rbegin())
                ++MultiIdx5;
        }
        return *uglyNum.rbegin();
    }

    int MinOf3Num(int a, int b, int c)
    {
        return min(a, min(b, c));
    }

    bool IsUgly(int num)
    {
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;
        return (num == 1) ? true : false;
    }
};

int main(void)
{
   Solution so; 
   int result = so.GetKthUglyNum(1500);
   cout << result << endl;
   cout << so.IsUgly(result) << endl;
   
   //cout << so.GetKthUglyNum(10) << endl;;
}
