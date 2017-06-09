#include <iostream>

using namespace std;

class HeapSort
{
    public:
        int* Heapsort(int *A, int n)
        {
            if(A == nullptr || n <= 0)
            {
                return nullptr;
            }
        }
        
        int* AdjustHeap(int *A, int n)
        {
            if(A == nullptr || n <= 0)
            {
                return nullptr;
            }
            int i = 1;
            while(i <= n/2)
            {
                if(2*i + 1 > n) //无右子树
                {
                    if(A[2*i] > A[i])
                    {
                        swap(A[2*i],A[i]);
                        i *= 2;
                    }
                }
                else
                {
                    if(A[2*i] > A[i]||A[2*i+1] > A[i])
                    {
                        int j;
                        A[2*i] > A[2*i+1] ? j = 2*i : j = 2*j + 1;
                        swap(A[j], A[i]);
                        i = j;
                    }
                }
            }
            return A;
        }

        int* CreateHeap(int *A, int n)
        {
            if(A == nullptr || n <= 0)
            {
                return nullptr;
            }
            int *array = new int[n+1];
            for(int i = 0; i < n; ++i)
            {
                array[i+1] = A[i];
            }

            for(int i = 1; i <= n; ++i)
            {
            }
            return array;
        }

#if 0
        void insert(int *A, int n, int data)
        {
            if(A==nullptr)
                return;
            A[n] = data;
            if(n == 0)
            {
                return;
            }
            int i = n;
            while((A[i] > A[i/2]) && (i > 0))
            {
                swap(A[i], A[i/2]);
                i /= 2;
            }
        }
#endif

}
