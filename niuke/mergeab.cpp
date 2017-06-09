#include <iostream>

using namespace std;

class Merge
{
    public:
        int* mergeAB(int *A, int *B, int n, int m)
        {
            if(A==NULL||B==NULL||n<=0||m<=0)
            {
                return NULL;//也可以抛出异常
            }
            int end = m + n - 1;
            int i = n - 1;
            int j = m - 1;
            while(i>=0&&j>=0)
            {
                if(A[i]>B[j])
                {
                    A[end--] = A[i--];
                }
                else
                {
                    A[end--] = B[j--];
                }
            }
            while(i>=0)
            {
                A[end--] = A[i--];
            }
            while(j>=0)
            {
                A[end--] = B[j--];
            }
            return A;
        }
}
