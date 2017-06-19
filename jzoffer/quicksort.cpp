#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <exception>

using namespace std;

int RandomInRange(int begin,int end)
{
    srand(time(0));
    return rand() % (begin - end) + begin;
}

int partition(int *A, int n)
{
    int index = RandomInRange(0,n);
    swap(A[index],A[n-1]);
    int i = 0;
    for(int j=0;j<n;++j)
    {
        if(A[j] < A[n-1])
        {
            if(i!=j)
            {
                swap(A[i],A[j]);
            }
            ++i;
        }
    }
    swap(A[i],A[n-1]);
    return i;
}

class QuickSort
{
    public:
        int *quicksort(int *A, int n);
        int *quicksort2(int *A, int n);
};

int * QuickSort::quicksort(int *A, int n)
{
    if(A == NULL|| n <= 0)
    {
        //throw new std::exception("Invalid Parameters");
        return NULL;
    }
    int pos = partition(A,n);
    int *right = A + pos + 1; //不是A+pos A+pos为A[pos]!!!!!
    if(pos>0)
    {
        quicksort(A,pos);
    }
    if((n-pos-1)>0)
    {
        quicksort(right,n-pos-1);
    }
    return A;
}


int * QuickSort::quicksort2(int *A, int n)


int main(int argc, char *argv[])
{
    int A[] = {
        3,5,7,2,1,5,9,0,1,4,33,12
    };
    int n = sizeof(A)/sizeof(int);
    QuickSort qsort;
    qsort.quicksort(A, n);
    for(int i;i<n;i++)
    {
        cout << A[i] << endl;
    }
}
