class ShellSort {
    public:
        int* shellSort(int* A, int n) {
            int step = n / 2;
            while(step)
            {
                for(int i = step; i < n; i++)
                {
                    while(i - step >= 0)
                    {
                        if(A[i] < A[i - step])
                        {
                            swap(A[i], A[i - step]);
                            i -= step;
                        }
                        else
                            break;
                    }
                }
                step /= 2;
            }
            return A;
            
        }
};
