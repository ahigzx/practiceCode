class Translation {
    public:
        string stringTranslation(string A, int n, int len) {
            if(len > n || n <=0 || len <=0)
                return NULL;
            int left = n - len;
            reverseWord(A, 0, n - 1);
            reverseWord(A, 0, left - 1);
            reverseWord(A, left, n - 1);
            return A;
        }

        void reverseWord(string& str, int start, int end)
        {
            while(start < end)
            {
                swap(str[start++], str[end--]);
            }
        }
}
