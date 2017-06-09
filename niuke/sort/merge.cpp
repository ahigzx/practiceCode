#include <iostream>

using namespace std;

class MergeSort {
    public:
        int* mergeSort(int*A, int n) {

            if((A==NULL)||(n<0))
            {

                return NULL;

            }
            int *temp = new int[n];
            _mergesort(A, 0, n-1, temp);
            return A;

            // write code here
            //     
        }
        void _mergesort(int* A, int begin, int end ,int *temp)
        {

            if(A==NULL)
            {

                return;

            }   
            if(end > begin)
            {
                int m = begin + (end - begin)/2;
                _mergesort(A, begin, m, temp);
                _mergesort(A, m+1, end, temp);
                merge(A, begin, end, temp);
            }

        }

        void merge(int *A, int begin, int end, int *temp)
        {

            int i = begin;
            int mid = begin + (end - begin)/2;
            int j = mid + 1;
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

            for(int h=0;h<(end-begin+1);h++)
            {

                A[begin+h] = temp[h];

            }

        }

};


int main(int argc, char *argv[])
{
    int a[] = {1,2,3,4,5,621,3,5,1,7,2,3,5,7,90,21,3};
    int length = sizeof(a)/sizeof(int);
    MergeSort s1;
    int *p = s1.mergeSort(a, length);
    for(int i=0;i<length;i++)
    {
        cout << a[i] << endl;
    }
}
