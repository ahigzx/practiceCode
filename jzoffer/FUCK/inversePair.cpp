#include <iostream>
#include <vector>

using namespace std;

int InversePairCore(vector<int>& nums, int start, int end, vector<int>& temp)
{
    if(start == end)
    {
        temp[start] = nums[start];
        return 0;
    }

    int mid = start + (end - start) / 2;
    int left = start;
    int right = mid + 1;
    int invesepairNum = 0;
    int k = start;
    int leftPairNum = InversePairCore(nums, start, mid, temp);
    int rightPairNum = InversePairCore(nums, mid+1, end, temp);
    while(left <= mid && right <= end)
    {
        if(nums[left] < nums[right])
        {
            temp[k++] = nums[left++];
        }
        else //left下标的数大于right下标的数,从left开始到mid之间都和nums[right]形成逆序数对
        {
            temp[k++] = nums[right++];
            invesepairNum += mid - left + 1; //左右各选一个的逆序数对数
        }
    }
    while(left <= end)
    {
        temp[k++] = nums[left++];
    }
    while(right <= end)
    {
        temp[k++] = nums[right++];
    }
    for(int i = start; i <= end; i++)
    {
        nums[i++] = temp[i++];
    }
    return invesepairNum + leftPairNum + rightPairNum;
}
int InversePair(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int length = nums.size();
    vector<int> temp(length);
    int count = InversePairCore(nums, 0, length - 1, temp);
    return count;
}

//比较的同时保持两边的顺序，以免重复计算



int main(void)
{

}
