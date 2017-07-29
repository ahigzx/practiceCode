class HeapSort {
    public:
        int* heapSort(int* A, int n) {
            for(int i = n / 2 - 1; i >= 0; i--)   //先将A堆化
                MinHeapFixdown(A, i, n);  
            for(int i = n - 1; i >= 1; i--)
                MinHeapFixdown(A, 0, i);
            return A;
            
        }

        void adjustHeap(int* A, int i, int n)
        {
            int temp = A[i];
            int j = 2 * i + 1; //数组从0开始左子树2i + 1
            while(j < n)
            {
                if(j+1 < n && A[j+1] < A[j])
                    j++;
                if(A[j] > temp)
                    break;
                A[i] = A[j];
                i = j;
                j = 2 * i + 1;
            }
            A[i] = temp;
        }
};
