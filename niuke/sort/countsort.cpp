#include <iostream>
#include <queue>

using namespace std;

class CountSort
{
    public:
        int* countSort(int *A, int n)
        {
            if(A==NULL||n<=0)
            {
                return NULL;//可打印一下
            }
            int* min = NULL;
            int* max = NULL;
            min = new int();
            max = new int();
            findmaxandmin(A, n, max, min);
            int length = *max - *min + 1;
            queue<int>* bucket = new queue<int>[length];
            for(int i=0;i<n;i++)
            {
                bucket[A[i]-*min].push(A[i]);
            }
            int index = 0;
            for(int j=0;j<length;j++)
            {
                while(!(bucket[j].empty()))
                {
                    A[index++] = bucket[j].front();
                    bucket[j].pop();
                }
            }

            return A;
            
        }
        void findmaxandmin(int *A, int n, int *max, int *min)
        {
            if(max==NULL||min==NULL)
            {
                cout << "input error" <<endl;
                return;
            }
            *max = A[0];
            *min = A[0];

            for(int i=1;i<n;i++)
            {
                if(A[i]>*max)
                {
                    *max = A[i];
                }
                if(A[i]<*min)
                {
                    *min = A[i];
                }
            }
        }

};

int main(int argc, char *argv[])
{
    int A[] = {
        1,23,1,23,4,5,6,72,23,5,7,9
    };
    int length = sizeof(A)/sizeof(int);
    CountSort csort;
    csort.countSort(A, length);
    for(int i=0;i<length;i++)
    {
        cout << A[i] << endl;
    }

}
