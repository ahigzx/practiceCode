#include <iostream>

using namespace std;

class Bubblesort{
    public:
        int * bubblesort(int *A ,int n) {
            int i, j;
            int temp;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    jf(A[j]>A[j+1])
                    {
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }
                }
            }
            return A;
        }
}

