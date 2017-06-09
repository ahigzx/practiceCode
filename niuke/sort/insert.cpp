#include <iostream>
#include <algorithm>
using namespace std;

class InsertSort{
    public:
        int * insertSort(int *A, int n)
        {
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j>0;j--)
                {
                    if(A[j]<A[j-1])
                    {
                        swap(A[j],A[j-1]);
                    }
                }
            }
            return A;
        }
};

int main(int argc, char **argv)
{
    int A[13] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int n = 13;
    InsertSort sorta;
    int *array = sorta.insertSort(A,n);
    for(int i=0;i<n;i++)
    {
        cout << array[i] << endl;
    }
}
