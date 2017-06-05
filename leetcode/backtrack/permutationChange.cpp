#include <iostream>
#include <algorithm>
#include <stdio.h>


using namespace std;
typedef long long LL;
int x[105];
int n;

bool judgeNum(int *array, int n, int k)
{
    int larger = 0;
    int smaller = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(array[i] > array[i+1])
        {
            larger++;
            if(larger > n-k-1)
                return false;
        }
        else 
        {
            smaller++;
            if(smaller > k)
                return false;
        }
    }
    if(smaller == k)
        return true;
}

void Backtrack(int t, int k)
{

    if(t==n){

        if(judgeNum(x, n, k))
        {
            for(int i=1;i<=n;i++)
            {
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        return ;

    }
    for(int i=t;i<=n;i++)
    {

        swap(x[i],x[t]);
        Backtrack(t+1, k);
        swap(x[i],x[t]);

    }

}


int main()
{

    for(int i=1;i<105;i++)
    {
        x[i]=i;
    }
    int k;
    cin >> n;
    cin >> k;
    Backtrack(1, k);

    return 0;

}
