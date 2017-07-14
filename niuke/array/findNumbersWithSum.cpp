class Solution {
    public:
        vector<int> FindNumbersWithSum(vector<int> array,int sum) {
            vector<int> res;
            if(array.empty())
                return res;
            int tail = array.size() - 1;
            int start = 0;
            while(start < tail)
            {
                if(array[start] + array[tail] < sum)
                {
                    ++start;
                }
                else if(array[start] + array[tail] > sum)
                {
                    --tail;
                }
                else
                {
                    res.push_back(array[start]);
                    res.push_back(array[tail]);
                    return res;
                }
            }
            return res;
        }
};
