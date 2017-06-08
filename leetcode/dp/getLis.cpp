class LongestIncreasingSubsequence {

    public:
        int getLIS(vector<int> A, int n) {
            if(A.empty() || n <= 0)
            {
                return 0;
            }
            vector<int> LisLen(n, 0);   //LisLen表示必须以A[i]结尾的最长子序列长度
            LisLen[0] = 1;
            int max = 0;
            for(int i = 1; i < n; i++)
            {
                int count = 0;
                int maxLen = 1;
                int preIndex = 0;
                for(int j = 0; j < i; j++)
                {
                    if(A[j] < A[i])
                    {
                        count++;
                        if(LisLen[j] > maxLen)
                        {
                            maxLen = LisLen[j]; //找出小于当前A[i]的前面的数的序数的最大值
                            preIndex = j;
                        }
                    }
                }
                if(count == 0)
                {
                    LisLen[i] = 1;
                }
                else
                {
                    LisLen[i] = LisLen[preIndex] + 1;
                }
                if(LisLen[i] > max)
                {
                    max = LisLen[i];
                }
            }
            return max;
            
        }

};
