#include <iostream>
#include <vector>

using namespace std;

int getFirstPosofK(const vector<int>& vec, int k)
{
    int high = vec.size() - 1;
    int low = 0;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(vec[mid] == k)
        {
            if(vec[mid-1] != k)
                return mid;
            else
                high = mid - 1;
        }
        else if(vec[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int getLastPosofK(const vector<int>& vec, int k)
{
    int high = vec.size() - 1;
    int low = 0;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(vec[mid] == k)
        {
            if(vec[mid+1] != k)
                return mid;
            else
                low = mid + 1;
        }
        else if(vec[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int getNumbersofK(const vector<int>& vec, int k)
{
    if(vec.empty())
        return 0;
    int firstPos = getFirstPosofK(vec, k);
    int lastPos = getLastPosofK(vec, k);
    if(firstPos > -1 && lastPos > -1)
    {
        return lastPos - firstPos + 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    vector<int> vec{
        2,2,2,2,3,4,5
    };
    cout << getNumbersofK(vec, 2) << endl;
}
