#include <iostream>

using namespace std;

class MergeSort{
    public:
        void *mergeSort(int *A, int begin, int end, int *temp);
};

void MergeSort::mergeSort(int *A, int begin, int end, int *temp)
{
    if(A==NULL)
    {
        return;
    }
    int m = begin + (end - begin)/2;
    mergeSort(A, begin, m, temp);
    mergeSort(A, m+1, end, temp);
    merge(A, begin, end, temp);
}


void merge(int *A, int begin, int end, int *temp)
{
    int i = begin;
    int mid = begin + (end - begin)/2;
    int j = mid+1;
    int k = 0;
    while((i <= mid) && (j <= end))
    {
        if(A[i]<A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    while(j<=end)
    {
        temp[k++] = A[j++];
    }
    while(i<=mid)
    {
        temp[k++] = A[i++];
    }
    for(i=0;i<(end-begin+1);i++)
    {
        A[begin+i] = temp[i];
    }
}


void merge_vesion2(int* A, int begin, int end, int* temp)
{
    int left = begin;
    int mid = begin + (end - begin) / 2;
    int right = mid + 1;
    int k = left; //temp空间从begin开始加入元素
    while(left < mid || right < end)  //只要有一边还有元素就不退出循环 为什么是<不是<=? shit  
    {
        if(right >= end || (left < mid && A[left] < A[right])) //右边一半到末尾了或者左边元素小于右边元素
        {
            temp[k++] == A[left++];
        }
        else
        {
            temp[k++] == A[right++];
        }
    }
    for(int i = begin; i <= end - begin; i++)
    {
        A[i] = temp[i];
    }
}
