#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
/*
 * 累加更新最大值，遇到和小于0就抛弃前面的和，重新累加  O(n)
 *
 * 
*/
int GreatestSubsum(const vector<int>& vec)
{
    assert(vec.size());
    int greatestSubsum = 0x80000000;
    int curSum = 0;
    for(auto x : vec)
    {
        curSum += x;
        if(curSum > greatestSubsum)
        {
            greatestSubsum = curSum;
        }

        if(curSum < 0)
        {
            curSum = 0;
        }
    }
    return greatestSubsum;
}

/*version2  O(nlogn)*/


int maxSubsum(const vector<int>& vec, int start, int end)
{
    assert(end > start && vec.size());
    if(end - start == 1)
        return vec[start];
    int mid = start + (end - start) / 2;
    int leftmax = maxSubsum(vec, start, mid);
    int rightmax = maxSubsum(vec, mid, end);
    int leftMidmax = vec[mid-1];
    int rightMidmax = vec[mid];
    int tempsum = 0;
    for(int i = mid - 1; i >= start ; i--)
    {
        tempsum += vec[i];
        leftMidmax = leftMidmax > tempsum ? leftMidmax : tempsum;
    }
    for(int i = mid; i <= end; i++)
    {
        tempsum += vec[i];
        rightMidmax = rightMidmax > tempsum ? rightMidmax : tempsum;
    }
    int midmax = leftMidmax + rightMidmax;
    return max(midmax, max(leftmax, rightmax));
}

int main(int argc, char** argv)
{
    vector<int>vec{
        -1,-2,-3,-10,-4,-7,-2,-5
    };
    cout << GreatestSubsum(vec) << endl;
    cout << maxSubsum(vec, 0, vec.size()-1) << endl;
}


