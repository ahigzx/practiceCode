class Solution {
    public:
        vector<vector<int> > FindContinuousSequence(int sum) {
            vector<vector<int>> res;
            if(sum < 3)
                return res;
            int small = 1;
            int big = 2;
            int curSum = 3;
            int middle = (1 + s) / 2;
            vector<int> seq;
            while(small < middle)
            {
                if(curSum == sum)
                {
                    for(int i = small; i <= big; ++i)
                    {
                        seq.push_back(i);
                    }
                    res.push_back(seq);
                }
                while(curSum > sum && small < middle)
                {
                    curSum -= small++;
                    if(curSum == sum)
                    {
                        for(int i = small; i <= big; ++i)
                        {
                            seq.push_back(i);
                        }
                        res.push_back(seq);
                    }
                }
                curSum += ++big;
            }
            return res;
        }
};
