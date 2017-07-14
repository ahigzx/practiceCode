class Solution {
    public:
        bool IsContinuous( vector<int> numbers ) {
            if(numbers.empty())
                return false;
            int count0 = 0;
            sort(numbers.begin(), numbers.end());
            for(auto& x : numbers)
            {
                if(x == 0)
                {
                    ++count0;
                }
            }
            int n = numbers.size();
            int countGap = 0;
            for(int i = 0; i < n - 1; ++i)
            {
                if(numbers[i + 1] == numbers[i])
                    return false;
                countGap += numbers[i + 1] - numbers[i] - 1;
            }
            if(countGap <= count0)
                return true;
            else
                return false;
        }
};
