#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

int partition(vector<int>& nums, int start, int end)
{
    int pivot = nums[start];
    int begin = start + 1;
    int i = begin;
    int j = end;
    while(true)
    {
        while(i < j&&nums[j] <= pivot)
            --j;
        if(i > j)
            break;
        while(i < j&&nums[i] >= pivot)
            ++i;
        if(i > j)
            break;
        swap(nums[i++], nums[j--]);
    }
    swap(nums[j], nums[start]);
    return j;
}


int findLargestKth(vector<int>& nums, int k)
{
    int mid;
    int start = 0;
    int end = nums.size() -1;
    mid = partition(nums, start, end);
    while(mid != k -1)
    {
        if(mid < k - 1)
        {
            start = mid + 1;
            mid = partition(nums, start, end);
        }
        else
        {
            end = mid - 1;
            mid = partition(nums, start, end);
        }
    }
    return nums[k-1];
}

void quicksort(vector<int>& nums, int start, int end)
{
    if(start == end)
        return;
    int pos = partition(nums, start, end);
    if(pos > start)
    {
        quicksort(nums, start, pos - 1);
    }
    if(end > pos)
    {
        quicksort(nums, pos + 1, end);
    }
}
int main(void)
{
    vector<int> vec{
        5,1,2,3,4
    };
    //int num = findLargestKth(vec, 3);
    quicksort(vec, 0, 4);
    for(auto num : vec)
    {
        cout << num << endl;
    }
    
}
