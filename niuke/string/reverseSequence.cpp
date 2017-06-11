class Reverse {
    public:
        string reverseSentence(string A, int n) {
            reverseWord(A, 0, n-1);
            int start = 0;
            int end = 0;
            while(end < n)
            {
                if(A[end] == ' ')
                {
                    reverseWord(A, start, end - 1);
                    start = end + 1;
                }
                ++end;
            }
            reverseWord(A, start, end - 1);
            return A;
            
        }
        void reverseWord(string& str, int start, int end)
        {
            while(start < end)
            {
                swap(str[start++], str[end--]);
            }
        }
};
