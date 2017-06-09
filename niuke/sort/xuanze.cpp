#include <iostream>

using namespace std;

class Selectionsort{
    public:
        int * selectionSort(int *A, int n){
            int min_index = 0;
            for(int i=0;i<n-1;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(A[j]<=A[min_index])
                    {
                        min_index = j; 
                    }
                }
                if(i!=min_index)
                {
                    swap(A[i],A[min_index]);
                }
                min_index = i+1;
            }
            return A;
        }
};


int main(int argc, char **argv)
{
    int A[13] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int n = 13;
    Selectionsort sorta;
    int *array = sorta.selectionSort(A,n);
    for(int i=0;i<n;i++)
    {
        cout << array[i] << endl;
    }
}
