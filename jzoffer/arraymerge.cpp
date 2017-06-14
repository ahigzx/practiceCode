#include <iostream>

using namespace std;

class arrayMerge
{
    public:
        void arraymerge(int *a, int *b, int alen, int blen)
        {
            if(a==NULL||b==NULL||alen<0||blen<0)
                return;
            int aIndex = alen - 1;
            int bIndex = blen - 1;
            int tail = alen + blen - 1;
            while(aIndex >= 0 && bIndex >= 0)
            {
                if(a[aIndex] > b[bIndex])
                {
                    a[tail] = a[aIndex];
                    --aIndex;
                }
                else
                {
                    a[tail] = b[bIndex];
                    --bIndex;
                }
                --tail;
            }
            if(bIndex >= 0)
            {
                for(int i=0;i<=bIndex;i++)
                {
                    a[i] = b[i];
                }
            }

        }
};

int main(int argc, char *argv[])
{
    int a[20] = {-1,23,45,67,89,90,91,92,93,100};
    int b[10] = {1,2,3,4,5,6,7,8,88,94};
    arrayMerge c;
    c.arraymerge(a, b, 10, 10);
    for(int i=0;i<20;i++)
    {
        cout << a[i] << endl;
    }
}

    
